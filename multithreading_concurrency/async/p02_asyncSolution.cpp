#include <iostream>
#include <string>
#include <chrono>
#include <future> // Include the <future> header

using namespace std::chrono;

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

    // Use std::async to fetch data concurrently
    auto dbFuture = std::async(std::launch::async, fetchDataFromDB, "Data");
    auto fileFuture = std::async(std::launch::async, fetchDataFromFile, "Data");

    // Wait for the futures to complete and get the results
    std::string dbData = dbFuture.get();
    std::string fileData = fileFuture.get();

    // Merge the data
    std::string mergedData = dbData + " + " + fileData;
    std::cout << "Merged Data: " << mergedData << std::endl;

    // Get the end time
    auto end = system_clock::now();
    auto diff = duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

    return 0;
}

/*
In this modified version, std::async creates two asynchronous tasks that fetch data from the database and the file system concurrently. The main thread waits for the results using get(). As a result, the total execution time is significantly reduced, and the program remains responsive during the data retrieval process.
*/