#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <thread>
#include <chrono>
#include <ctime>

class Sorter : public olc::PixelGameEngine {
    public:
        Sorter() {
            sAppName = "Sorting Algorithm";
        }

    public:

        std::vector<uint8_t> array;
    
        bool OnUserCreate() override {
            // Called once at the start, so create things here
            array.resize(40);
            
            std::generate(
                          array.begin(),
                          array.end(),
                          []() { return rand() % 50; }
                          );
            
            return true;
        }
    
        int temp;
        int i = 0, j = 0;
    
        bool OnUserUpdate(float fElapsedTime) override {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            sortArray();
            return true;
        }
        
        void DrawArray()
        {
            int j = 0;
            
            for(auto &i : array)
            {
                DrawLine(j, 50, j, 50 - i, olc::CYAN);
                j += 2;
            }
        }
    
        void sortArray()
        {
            if(j < 39 - i)
            {
                if(array[j] > array[j + 1])
                {
                     Clear(olc::WHITE);
                     int temp;
                     temp=array[j];
                     array[j]=array[j + 1];
                     array[j + 1]=temp;
                     
                     DrawArray();
                }
                j++;
            }
            else{
                j = 0;
                i++;
                if (i == 40)
                    i = 0;
            }
        }
        
        
};


int main(int argc, char const *argv[]) {
	Sorter demo;
	if (demo.Construct(100, 50, 10, 10))
		demo.Start();

	return 0;
}
