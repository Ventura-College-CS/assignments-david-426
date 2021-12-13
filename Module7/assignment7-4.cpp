#include <iostream>
using namespace std;

void hanoiTower(int, int, int, int);

int main()
{
    cout << "Originally the 5 discs are all on the first tower\n";
    hanoiTower(5, 1, 2, 3);
}

void hanoiTower(int num_discs, int from, int temp, int to)
{
    if (num_discs > 0)
    {
        hanoiTower(num_discs - 1, from, to, temp);
        cout << "Move a disk in " << from << " to " << to << " using " << temp << endl;
        hanoiTower(num_discs - 1, temp, from, to);
    }
}

/*This program shows the steps for the towers of hanoi mathematical game of moving towers around on 3 pegs where the discs must only be moved 1 at a time, cannot be placed on smaller discs,
and must be stored on a peg at all times except when moving a disc. The job of the program is to show the steps to be taken for moving the tower from the 1st peg to the 3rd based on the 
games rules.

after running the program the steps are as follows for a version with 5 discs (to simplify this I will use 1 to 5 as the disk names with 1 being the top smallest disk):
to begin place disc 1 on peg 2
place disc 2 on peg 3
place disc 1 on peg 3 on top of disc 2
place disc 3 on peg 2
place disc 1 on peg 1 atop discs 4 and 5
place disc 2 on peg 2 atop disc 3
place disc 1 on peg 2 atop discs 2 and 3
place disc 4 on peg 3
place disc 1 on peg 3 atop disc 4
place disc 2 on peg 1 atop disc 5
place disc 1 on peg 1 atop discs 2 and 5
place disc 3 on peg 3 atop disc 4
place disc 1 on peg 2
place disc 2 on peg 3 atop discs 3 and 4
place disc 1 on peg 3 atop discs 2, 3, and 4
place disc 5 on peg 2 
place disc 1 on peg 2 atop disc 5
place disc 2 on peg 1 
place disc 1 on peg 1 atop disc 2
place disc 3 on peg 2 atop disc 5
place disc 1 on peg 3 atop disc 4
place disc 2 on peg 2 atop discs 3 and 5
place disc 1 on peg 2 ato discs 2, 3, and 5
place disc 4 on peg 1
place disc 1 on peg 1 atop disc 4
place disc 2 on peg 3
place disc 1 on peg 3 atop disc 2
place disc 3 on peg 1 atop disc 4 
place disc 2 on peg 1 atop discs 3 and 4
place disc 1 on peg 1 atop discs 2, 3, and 4
place disc 5 on peg 3 
place disc 1 on peg 3 atop disc 5
place disc 2 on peg 2
place disc 1 on peg 2 atop disc 2
place disc 3 on peg 3 atop disc 5
place disc 1 on peg 1 atop disc 4
place disc 2 on peg 3 atop discs 3 and 5
place disc 1 on peg 2 
place disc 2 on peg 1 atop disc 4
place disc 1 on peg 3 atop discs 3 and 5
place disc 2 on peg 2
place disc 1 on peg 2 atop disc 2
place disc 3 on peg 1 atop disc 4
place disc 1 on peg 2 atop discs 3 and 4
place disc 2 on peg 3 atop disc 5
place disc 1 on peg 3 atop discs 2 and 5
place disc 3 on peg 2
place disc 1 on peg 1 atop disc 4
place disc 2 on peg 2 atop disc 3
place disc 1 on peg 2 atop discs 2 and 3
place disc 4 on peg 3 atop disc 5
place disc 1 on peg 3 atop discs 4 and 5
place disc 2 on peg 1 
place disc 1 on peg 1 atop disc 2
place disc 3 on peg 3 atop discs 4 and 5
place disc 1 on peg 2 
place disc 2 on peg 3 atop discs 3, 4, and 5
finally place disc 1 on peg 3 atop discs 2, 3, 4, and 5
*/