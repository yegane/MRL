// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()
{
	int radius;
	// initialize a video capture object
	VideoCapture vid_capture(0);

	// Print error message if the stream is invalid
	if (!vid_capture.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
	}
	cout<<"enter your radius";
	// Read the frames to the last frame
	int size;
	cout << "\033[1;36m size :\044[0m ";
	cin >> size;
	while (vid_capture.isOpened())
	{
		// Initialise frame matrix
		Mat frame;
	    // Initialize a boolean to check if frames are there or not
		bool isSuccess = vid_capture.read(frame);

        Mat cir = frame.clone();
	    Point center(frame.cols/2.0,frame.rows/2.0);
    	circle(cir,center,size,Scalar(255, 255, 0), 2, 0, 0);

		// If frames are present, show it
		if(isSuccess == true)
		{
			//display frames
			imshow("Frame", cir);
		}

		// If frames are not there, close it
		if (isSuccess == false)
		{
			cout << "Video camera is disconnected" << endl;
			break;
		}
		
		//wait 20 ms between successive frames and break the loop if key q is pressed
		int k = waitKey(20);
		if (k == 113)
		{
			cout << "Q key is pressed by the user. Stopping the video" << endl;
			break;
		}
		
	}
	destroyAllWindows();
	vid_capture.release();
	return 0;
}