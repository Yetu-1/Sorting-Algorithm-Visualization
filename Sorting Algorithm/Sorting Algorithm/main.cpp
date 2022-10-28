#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <thread>
#include <chrono>
#include <ctime>

#define ARRAY_SIZE 50

class Sorter : public olc::PixelGameEngine
{
public:
    Sorter() {
        sAppName = "Sorting Algorithm";
    }

public:

    std::vector<uint8_t> array;

    bool OnUserCreate() override {
        // Called once at the start, so create things here
        array.resize(ARRAY_SIZE);
        
        std::generate(
                      array.begin(),
                      array.end(),
                      []() { return rand() % 50; }
                      );
        
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        bubble_sort(true);
        return true;
    }
    
    void DrawArray()
    {
        int j = (int)((ScreenWidth() - (ARRAY_SIZE*2))/2);
        
        for(auto &i : array)
        {
            DrawLine(j, 80, j, 80 - i, olc::CYAN);
            j += 2;
        }
    }

    void bubble_sort(bool order)
    {
        static int idx = 0, j = 0;
        static bool status = false;
        
        if(status == false)
        {
            if(j < ((ARRAY_SIZE-1) - idx))
            {
                if (order)
                    order = array[j] > array[j + 1];
                else
                    order = array[j] < array[j + 1];
                
                if(order)
                {
                    Clear(olc::WHITE);
                    int temp;
                    temp = array[j];
                    array[j]=array[j + 1];
                    array[j + 1] = temp;
                    DrawArray();
                }
                j++;
            }
            else{
                if (idx == ARRAY_SIZE)
                {
                    status = true;
                    idx = 0;
                }
                else
                {
                    j = 0;
                    idx++;
                }
            }
        }
    }
        

        
};


int main(int argc, char const *argv[]) {
	Sorter demo;
	if (demo.Construct(120, 80, 10, 10))
		demo.Start();

	return 0;
}
