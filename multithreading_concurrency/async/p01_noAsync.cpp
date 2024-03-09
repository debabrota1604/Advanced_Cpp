#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::chrono;


/*
The std::async function allows us to execute tasks asynchronously, potentially in separate threads. It’s particularly useful when we want to perform computationally expensive or time-consuming operations without blocking the main thread.

Suppose we have a scenario where we need to fetch data from a database and data from files in the file system. We want to merge both sets of data and print the result. Traditionally, in a single-threaded approach, we would do something like this:
*/

std::string fetchDataFromDB(std::string recvdData) {
    // Simulate fetching data from the database (takes 5 seconds)
    std::this_thread::sleep_for(seconds(5));
    // Do other DB-related stuff and return the data
    return "DB_" + recvdData;
}

std::string fetchDataFromFile(std::string recvdData) {
    // Simulate fetching data from a file (takes 5 seconds)
    std::this_thread::sleep_for(seconds(5));
    // Do other file-related stuff and return the data
    return "File_" + recvdData;
}

int main() {
    // Get the start time
    auto start = system_clock::now();

    // Fetch data from the database
    std::string dbData = fetchDataFromDB("Data");

    // Fetch data from a file
    std::string fileData = fetchDataFromFile("Data");

    // Merge the data (in this case, just concatenate the strings)
    std::string mergedData = dbData + " + " + fileData;
    std::cout << "Merged Data: " << mergedData << std::endl;

    // Get the end time
    auto end = system_clock::now();
    auto diff = duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

    return 0;
}

/*
In the above example, fetching data from the database and the file system sequentially takes a total of 10 seconds. However, we can improve this by using std::async to execute these tasks concurrently. Here’s how we can modify the code: In p02
*/