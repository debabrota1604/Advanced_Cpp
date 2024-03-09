// Image program (similar to above) to demonstrate working of CRTP
#include <chrono>
#include <iostream>
using namespace std;

typedef std::chrono::high_resolution_clock Clock;


/*
Curiously Recurring Template Pattern (CRTP) 
Usage of VPtr and VTable can be avoided altogether through Curiously Recurring Template Pattern (CRTP). CRTP is a design pattern in C++ in which a class X derives from a class template instantiation using X itself as template argument. More generally it is known as F-bound polymorphism. 
*/

// To store dimensions of an image
class Dimension {
public:
	Dimension(int _X, int _Y)
	{
		mX = _X;
		mY = _Y;
	}

private:
	int mX, mY;
};

// Base class for all image types. The template
// parameter T is used to know type of derived
// class pointed by pointer.
template <class T>
class Image {
public:
	void Draw()
	{
		// Dispatch call to exact type
		static_cast<T*>(this)->Draw();
	}
	Dimension GetDimensionInPixels()
	{
		// Dispatch call to exact type
		static_cast<T*>(this)->GetDimensionInPixels();
	}

protected:
	int dimensionX, dimensionY;
};

// For Tiff Images
class TiffImage : public Image<TiffImage> {
public:
	void Draw()
	{
		// Uncomment this to check method dispatch
		// cout << "TiffImage::Draw() called" << endl;
	}
	Dimension GetDimensionInPixels()
	{
		return Dimension(dimensionX, dimensionY);
	}
};

// There can be more derived classes like PngImage,
// BitmapImage, etc

// Driver code
int main()
{
	// An Image type pointer pointing to Tiffimage
	Image<TiffImage>* pImage = new TiffImage;

	// Store time before virtual function calls
	auto then = Clock::now();

	// Call Draw 1000 times to make sure performance
	// is visible
	for (int i = 0; i < 1000; ++i)
		pImage->Draw();

	// Store time after virtual function calls
	auto now = Clock::now();

	cout << "Time taken: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
		<< " nanoseconds" << endl;

	return 0;
}

/*
Virtual method vs CRTP benchmark 
The time taken while using virtual method was 2613 nanoseconds. This (small) performance gain from CRTP is because the use of a VTable dispatch has been circumvented. Please note that the performance depends on a lot of factors like compiler used, operations performed by virtual methods. Performance numbers might differ in different runs, but (small) performance gain is expected from CRTP. 
Note: If we print size of class in CRTP, it can be seen that VPtr no longer reserves 4 bytes of memory. 
*/
