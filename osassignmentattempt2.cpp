// osassignmentattempt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Authors: AMAL ISHAQ AHMED RASSAS,132835

#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <valarray>
#include <sstream>
#include <algorithm>

using namespace std;
class process {
    int NoOfProcesses=0;
    string ProcessName;
    int ArrivalTime;
    int ProcessTime;
public:
    process(){
       
   }
    process(int NoOfProcesses, string ProcessName, int ArrivalTime, int ProcessTime) {
       this->NoOfProcesses = NoOfProcesses;
       this->ProcessName = ProcessName;
       this->ArrivalTime = ArrivalTime;
       this->ProcessTime = ProcessTime;
   }
    void setprocessname(string processname) {
        ProcessName = processname;
    }
    void setarrivaltime(int arrivaltime) {
        ArrivalTime = arrivaltime;
    }
    void setprocesstime(int processtime) {
        ProcessTime = processtime;
    }
    int getarrivaltime() {
        return ArrivalTime;
    }
    int getprocesstime() {
        return ProcessTime;
    }
    string getprocessname() {
        return ProcessName;
    }
    int getlength() {
        return NoOfProcesses;
    }
    void print() {
        cout << ProcessName << " " << ArrivalTime << " " << ProcessTime << endl;
    }
   

};
void sort(process arr[] ,int length) {
  //  process *sorted = new process();
    int i, j;
    process processtemp;
    
  
   for (i = 0; i < length; i++)
   {
       for (j = i + 1; j < length; j++)
       {
           if (arr[i].getarrivaltime() > arr[j].getarrivaltime())
           {
               processtemp = arr[i];
               arr[i] = arr[j];
               arr[j] = processtemp;
           }
       }
   }

    
   /* for (int i = 0; i < length; i++) {
        arr[i].print();
    }*/
 
   


}
int main()
{
    ifstream inputfile("inputfile.txt");
    if (inputfile.fail()) {
        cout << "your input file didn't open successfully" << endl;
    }
    else {
        string s;
        string processname;
        string stringarrivaltime;
        string stringprocesstime;
        int arrivaltime;
        int processtime;
        int length;
        vector<string>fullvector;
        vector<int> intarrivaltime;
        vector<int> intprocessingtime;
        vector<char> vectorprocessname;
        string s1;
        int arrivaltosend;
        int processtosend;
        string nametosend;
        

        process *p ;

        while (getline(inputfile, s)) {
           /* processname = s[0];
            arrivaltime = s[2];
            processtime = s[3];
            cout << processname << " " << arrivaltime << " " << processtime << endl;*/
            //cout << s<<endl;
            fullvector.push_back(s);
           
        }
        length = fullvector.size()-1;
        p = new process[length];

        
        for (int i = 0; i < length; i++) {
            s1 = fullvector[i + 1];
            vectorprocessname.push_back(s1[0]);
            //var to store arrival time as string from the string 
            stringarrivaltime = s1[2];
            //var to store processing time as string from the string 
            stringprocesstime = s1[4];
            // we want to convert the string to int so we use the stringstream obj to do that 
            stringstream convertarrival(stringarrivaltime);
            convertarrival >> arrivaltime;
            intarrivaltime.push_back(arrivaltime);
            // we want to convert the string to int so we use the stringstream obj to do that
            stringstream convertprocessing(stringprocesstime);
            convertprocessing >> processtime;
            intprocessingtime.push_back(processtime);

        }
        for (int i = 0; i < length; i++) {
            nametosend = vectorprocessname[i];
            arrivaltosend = intarrivaltime[i];
            processtosend = intprocessingtime[i];
           // cout << nametosend << " " << arrivaltosend << " " << processtosend << endl;
            //process Process(length, nametosend, arrivaltosend, processtosend);
            p[i].setprocessname(nametosend);
            p[i].setarrivaltime(arrivaltosend);
            p[i].setprocesstime(processtosend);
        }
        //process* sortedprocess = new process();
         sort(p, length);
         int endtime=0;
         int turnaround;
         int delay;
         //loop to write process names sorted

         ofstream outputfile("outputfile.txt");
         for (int i = 0; i < length; i++)
             outputfile << p[i].getprocessname();
             outputfile << endl;
        
         for (int i = 0; i < length; i++) {


             endtime = endtime + p[i].getprocesstime(); 
             turnaround = endtime - p[i].getarrivaltime();  
             delay = turnaround - p[i].getprocesstime();
             
              outputfile << p[i].getprocessname() << ":(" << "response=" << delay << " ,turnaround=" << turnaround << " ,delay=" << delay << ")" << endl;
         }
            
        
        inputfile.close();
      

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
