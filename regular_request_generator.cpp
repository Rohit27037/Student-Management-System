#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TOTAL_PAIRS_REGULAR 50

int main() {
    clock_t start_time_regular = clock();
    
    srand(time(NULL));
    ofstream queueFile;

    for (int i = 0; i < TOTAL_PAIRS_REGULAR; i++) {
        int studentId = rand() % 100 + 1;
        int operationId = rand() % 4;

        time_t currentTime = time(NULL);
        struct tm* timeInfo = localtime(&currentTime);
        int hour = timeInfo->tm_hour;
        int minute = timeInfo->tm_min;
        int second = timeInfo->tm_sec;

        queueFile.open("operation_queue.txt", ios::app);

        if (operationId == 2) {
            int hostelRoom = rand() % 100;
            cout << "Generated: regular " << studentId << " " << operationId << " (" << hostelRoom << ") "
                 << hour << ":" << minute << ":" << second << endl;
            queueFile << "regular " << studentId << " " << operationId << " " << hostelRoom << " "
                      << hour << ":" << minute << ":" << second << endl;
            queueFile.flush();
        } else {
            cout << "Generated: regular " << studentId << " " << operationId << " "
                 << hour << ":" << minute << ":" << second << endl;
            queueFile << "regular " << studentId << " " << operationId << " " << 0 << " "
                      << hour << ":" << minute << ":" << second << endl;
            queueFile.flush();
        }

        queueFile.close();
        sleep(1);
    }

    clock_t end_time_regular = clock();
    double time_taken_regular = static_cast<double>(end_time_regular - start_time_regular) / CLOCKS_PER_SEC;
    cout << "Time taken by generateRegularRequests: " << time_taken_regular << " seconds" << endl;

    return 0;
}
