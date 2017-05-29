#ifndef FUNCTIONFILEREADER_H 
#define FUNCTIONFILEREADER_H 

// VProf libs
#include "Utils.h"

// STL libs
#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <stdexcept>
#include <algorithm>

enum Operation  { MUTEX_LOCK, MUTEX_UNLOCK,                // Mutexes
                  CV_WAIT, CV_BROADCAST, CV_SIGNAL,        // CVs
                  QUEUE_ENQUEUE, QUEUE_DEQUEUE,            // Queues
                  MESSAGE_SEND, MESSAGE_RECEIVE,           // Messaging 
                  MKNOD, OPEN, CLOSE, READ, WRITE, PIPE,   // IPC FIFO/pipe
                  MSGGET, MSGSND, MSGRCV };           	   // IPC message queue

struct LogInformation {
    unsigned int functionID;
    Operation op;
};

class FunctionFileReader {
    public:
        FunctionFileReader(const std::string _userFilename): 
        userFilename(_userFilename),
        funcMap(std::make_shared<std::unordered_map<std::string, std::string>>()), 
        opMap(std::make_shared<std::unordered_map<std::string, std::string>>()), 
        unqualifiedNames(std::make_shared<std::vector<std::string>>()), 
        qualifiedNames(std::make_shared<std::vector<std::string>>()),
        operationStrings({ "MUTEX_LOCK", "MUTEX_UNLOCK", "CV_WAIT",
                           "CV_BROADCAST", "CV_SIGNAL", "QUEUE_ENQUEUE",
                           "QUEUE_DEQUEUE", "MESSAGE_SEND", "MESSAGE_RECEIVE", 
                           "MKNOD", "CLOSE", "OPEN", "READ", "WRITE", "PIPE",
			   "MSGGET", "MSGSND", "MSGRCV" }),
        beenParsed(false) {}
        
        // Parse the file
        void Parse();

        // Returns the function map generated by parse.
        // Parse must be called prior to this.
        std::shared_ptr<std::unordered_map<std::string, std::string>> GetFunctionMap();

        // Returns a map of qualified function name to log info struct
        std::shared_ptr<std::unordered_map<std::string, std::string>> GetOperationMap();

        // Returns a vector of all the qualified function names.
        // Parse must be called prior to this.
        std::shared_ptr<std::vector<std::string>> GetQualifiedFunctionNames();

        // Returns a vector of all the unqualified function names.
        // Parse must be called prior to this.
        std::shared_ptr<std::vector<std::string>> GetUnqualifiedFunctionNames();

    private:
        const std::string userFilename;
        std::shared_ptr<std::unordered_map<std::string, std::string>> funcMap;
        std::shared_ptr<std::unordered_map<std::string, std::string>> opMap;
        std::shared_ptr<std::vector<std::string>> unqualifiedNames;
        std::shared_ptr<std::vector<std::string>> qualifiedNames;

        std::set<std::string> operationStrings;

        bool beenParsed;

        void Parse(const std::string &filename);
};

#endif
