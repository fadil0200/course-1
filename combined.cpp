#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;


const double MAX_SHOULDER_ANGLE = 20; 
const double MIN_SHOULDER_AREA = 2000; 
const double MIN_SHOULDER_ASPECT_RATIO = 0.3; 


bool captureReferenceFaces(const string& filename) {
    CascadeClassifier faceCascade;
    string cascadePath = "/home/fido/opencv/data/haarcascades/haarcascade_frontalface_default.xml";
    if (!faceCascade.load(cascadePath)) {
        cerr << "Error: Unable to load face cascade." << endl;
        return false;
    }

    VideoCapture videoCapture(0);
    if (!videoCapture.isOpened()) {
        cerr << "Error: Unable to open video capture device." << endl;
        return false;
    }

    vector<Mat> referenceFaces;
    int numFacesToCapture = 5;
    cout << "Please capture your face multiple times..." << endl;
    for (int i = 0; i < numFacesToCapture; ++i) {
        Mat frame;
        videoCapture >> frame;
        if (frame.empty()) {
            cerr << "Error: Unable to capture frame." << endl;
            break;
        }

        Mat frameGray;
        cvtColor(frame, frameGray, COLOR_BGR2GRAY);

        vector<Rect> faces;
        faceCascade.detectMultiScale(frameGray, faces, 1.3, 5);

        for (const Rect& faceRect : faces) {
            Mat face = frameGray(faceRect);
           
            Mat resizedFace;
            resize(face, resizedFace, Size(100, 100));
            referenceFaces.push_back(resizedFace);
            rectangle(frame, faceRect, Scalar(255, 0, 0), 2);
        }

        imshow("Capture Reference Faces", frame);
        waitKey(1000);
    }

    videoCapture.release();
    destroyAllWindows();

  
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to save captured faces." << endl;
        return false;
    }
    outFile << referenceFaces.size() << endl;
    for (size_t i = 0; i < referenceFaces.size(); ++i) {
        string imagePath = "reference_face_" + to_string(i) + ".jpg";
        imwrite(imagePath, referenceFaces[i]);
        outFile << imagePath << " 0" << endl; 
    }
    outFile.close();

    cout << "Reference faces captured and saved successfully." << endl;
    return true;
}


bool loadReferenceFaces(const string& filename, vector<Mat>& referenceFaces, vector<int>& referenceLabels) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to load reference faces." << endl;
        return false;
    }

    int numFaces;
    file >> numFaces;
    for (int i = 0; i < numFaces; ++i) {
        string imagePath;
        int label;
        file >> imagePath >> label;
        Mat face = imread(imagePath, IMREAD_GRAYSCALE);
        if (face.empty()) {
            cerr << "Error: Unable to load reference face: " << imagePath << endl;
            return false;
        }
        referenceFaces.push_back(face);
        referenceLabels.push_back(label);
    }
    return true;
}


void detectShouldersAndDirection(Mat& frame, Mat& frameGray) {
  
    Mat blurred;
    GaussianBlur(frameGray, blurred, Size(5, 5), 0);
    Mat thresholded;
    threshold(blurred, thresholded, 50, 255, THRESH_BINARY);

 
    vector<vector<Point>> contours;
    findContours(thresholded, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


    vector<vector<Point>> shoulderContours;
    for (const auto& contour : contours) {
        double area = contourArea(contour);
        if (area >= MIN_SHOULDER_AREA) {
            RotatedRect rotatedRect = minAreaRect(contour);
            if (rotatedRect.size.width > 0 && rotatedRect.size.height > 0) {
                double aspectRatio = max(rotatedRect.size.width, rotatedRect.size.height) / min(rotatedRect.size.width, rotatedRect.size.height);
                if (aspectRatio >= MIN_SHOULDER_ASPECT_RATIO) {
                    double angle = abs(rotatedRect.angle);
                    if (angle <= MAX_SHOULDER_ANGLE || angle >= (90 - MAX_SHOULDER_ANGLE)) {
                        shoulderContours.push_back(contour);
                    }
                }
            }
        }
    }

    
    sort(shoulderContours.begin(), shoulderContours.end(), [](const vector<Point>& a, const vector<Point>& b) {
        return boundingRect(a).x < boundingRect(b).x;
    });


    vector<Point> leftShoulder, rightShoulder;
    if (shoulderContours.size() >= 2) {
        leftShoulder = shoulderContours[0];
        rightShoulder = shoulderContours[1];

    
        Point leftShoulderCenter = boundingRect(leftShoulder).tl() + boundingRect(leftShoulder).br();
        leftShoulderCenter *= 0.5;
        Point rightShoulderCenter = boundingRect(rightShoulder).tl() + boundingRect(rightShoulder).br();
        rightShoulderCenter *= 0.5;
        double dx = rightShoulderCenter.x - leftShoulderCenter.x;
        double dy = rightShoulderCenter.y - leftShoulderCenter.y;
        double angle = atan2(dy, dx) * 180 / CV_PI;

     
        string direction;
        if (angle > 10)
            direction = "Right";
        else if (angle < -10)
            direction = "Left";
        else
            direction = "Straight";

     
        cout << "Shoulder Direction: " << direction << endl;
    } else {
        cout << "Could not detect shoulders. Number of contours: " << shoulderContours.size() << endl;
    }

  
    drawContours(frame, shoulderContours, -1, Scalar(0, 255, 0), 2);
}

int main() {
   
    if (!captureReferenceFaces("reference_faces.txt")) {
        return 1;
    }

   
    vector<Mat> referenceFaces;
    vector<int> referenceLabels;
    if (!loadReferenceFaces("reference_faces.txt", referenceFaces, referenceLabels)) {
        return 1;
    }

   
    CascadeClassifier faceCascade;
    string cascadePath = "/home/fido/opencv/data/haarcascades/haarcascade_frontalface_default.xml";
    if (!faceCascade.load(cascadePath)) {
        cerr << "Error: Unable to load face cascade." << endl;
        return 1;
    }


    VideoCapture videoCapture(0); 
    if (!videoCapture.isOpened()) {
        cerr << "Error: Unable to open video capture device." << endl;
        return 1;
    }

    while (true) {
        Mat frame;
        videoCapture >> frame;
        if (frame.empty()) {
            cerr << "Error: Unable to capture frame." << endl;
            break;
        }

        Mat frameGray;
        cvtColor(frame, frameGray, COLOR_BGR2GRAY);

        vector<Rect> faces;
        faceCascade.detectMultiScale(frameGray, faces, 1.3, 5);

        for (const Rect& faceRect : faces) {
            Mat face = frameGray(faceRect);
            resize(face, face, Size(100, 100));

           
            double minDist = DBL_MAX;
            int minIndex = -1;
            for (size_t j = 0; j < referenceFaces.size(); ++j) {
                double dist = norm(face, referenceFaces[j], NORM_L2);
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = j;
                }
            }

           
            if (minIndex != -1) {
                string result = "Match (Distance: " + to_string(minDist) + ")";
                putText(frame, result, Point(faceRect.x, faceRect.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);

                
                detectShouldersAndDirection(frame, frameGray);
            } else {
                putText(frame, "No Match", Point(faceRect.x, faceRect.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 2);
            }

            rectangle(frame, faceRect, Scalar(255, 0, 0), 2);
        }

        
        imshow("Face Detection and Recognition", frame);

        if (waitKey(1) == 27) { // ESC key
            break;
        }
    }

    videoCapture.release();
    destroyAllWindows();

    return 0;
}
