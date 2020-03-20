
#include <opencv.hpp>

using namespace cv;
using namespace std;
//Á·Ï°Ò»
/*
int main() {
	Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
	Mat image = imread("D:\\textphoto\\coin.png", 0);
	Mat src;
	Mat dst;
    threshold(image, src, 0, 255, THRESH_OTSU);
	 morphologyEx( src,  dst,
		  MORPH_ERODE,  kernel);
	 imshow("src", src);
	imshow("image",dst);

	waitKey(0);
	

}
*/

//Á·Ï°¶þ

/*int main() {
	Mat src;
	Mat dst;
	Mat statsMat;
	Mat centroids;

	

	Mat image = imread("D:\\textphoto\\coin.png", 0);
	threshold(image, src, 0, 255, THRESH_OTSU);
	int n = connectedComponentsWithStats( src, dst,
		 statsMat ,  centroids,
		 8 , CV_32S
	);
	for (int i = 1;i < n;i++) {
		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width= statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(src, bndbox, CV_RGB(255, 255, 255), 1,8, 0);
	}
	imshow("result", src);
	cout << n-1 << endl;
	waitKey(0);
}*/

//Á·Ï°Èý
int main() {
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 10));
	Mat image = imread("D:\\textphoto\\9.jpg", 0);
	Mat src;
	Mat dst;
	Mat ccc;
	Mat result;
	Mat statsMat;
	Mat centroids;
	
	threshold(image, ccc, 30, 255, THRESH_BINARY_INV);
	morphologyEx(ccc, src,
		MORPH_ERODE, kernel);

			int n = connectedComponentsWithStats( src, dst,
		 statsMat ,  centroids,
		8 , CV_32S
	);
	for (int i = 1;i < n;i++) {
		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width= statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(src, bndbox, CV_RGB(255, 255, 255), 1,8, 0);
	}
	imshow("result1", src);
	cout << n-1 << endl;

	waitKey(0);
}