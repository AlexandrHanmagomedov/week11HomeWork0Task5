/*
Напишите рекурсивную функцию, которая принимает
одномерный массив из 100 целых чисел, заполненных
случайным образом, и находит позицию, с которой
начинается последовательность из  10 чисел, сумма
которых минимальна.
*/
#include <iostream>
#include<time.h>
using namespace std;

int MinPoslPoz(int a[100], int mMPP, int temp1 = 0, int Sum1 = 0, int Sum2 = 0, int arrtemp = 0) {
    int newSum = Sum2 + a[arrtemp];
    if (arrtemp == mMPP) {
        return temp1;
    }
    if (arrtemp < 10) {
        return MinPoslPoz(a, temp1, newSum, newSum, arrtemp + 1);
    }
    newSum = newSum - a[arrtemp - 10];
    if (newSum > Sum1) {
        return MinPoslPoz(a, arrtemp - 10, newSum, newSum, arrtemp + 1);
    }
    else {
        return MinPoslPoz(a, temp1, Sum1, newSum, arrtemp + 1);
    }
}
int main() {

    srand(time(0));
    const int m = 100;
    int Arr[m];
    for (int i = 0; i < m; i++) {
        Arr[i] = rand() % 100;
        int count = i;
        cout << "poz" << count << "\t[" << Arr[i] << "]\n";
    }
    cout << "\n\n";

    MinPoslPoz(Arr, m);
    int  poz = MinPoslPoz(Arr, m);
    cout << "Minimum position: " << poz << endl << endl;

}















//
//#include <iostream>
//#include<time.h>
//using namespace std;
//int poz;
//template <typename PM>
//PM PosledMinim(PM ArrPM[], int mPM, int poz, int KonPM)
//{
//    int Sum = 0;
//    for (int i = Na4PM; i < mPM + 10; i++)
//    {
//        Sum += ArrPM[i];
//        cout << "poziciya " << mPM << "; sum: " << Sum << endl;
//    }
//    if (mPM - Na4PM == 10)
//    {
//        KonPM = mPM;
//        return Sum;
//        //minPM = Sum;
//        //Na4PM = i;
//        //KonPM = mPM - 1;
//    }
//    else {
//        int Sum1 = PosledMinim(ArrPM[], Na4PM + 1, KonPM);
//
//        if (Sum <= Sum1)
//        {
//            KonPM = mPM;
//            return Sum;
//        }
//        else {
//            return Sum1;
//        }
//    }
//
//    //PosledMinim(ArrPM, mPM - 1, minPM, Na4PM, KonPM);
//
//}
//
//
//
//int main()
//{
//    srand(time(0));
//    const int m = 100;
//    int Arr[m];
//    for (int i = 0; i < m; i++) {
//        Arr[i] = rand() % 100;
//    }
//    cout << "\n\n";
//
//    cout << "\n\n";
//
//    PosledMinim(Arr, m, 0, poz);
//}