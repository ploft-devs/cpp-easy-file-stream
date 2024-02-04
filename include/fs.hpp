#pragma once
#include <fstream>
#include <string>
#include <vector>
#include<iostream>
#include <iterator>
#include <sstream>
/**
 * @brief Class to access a input file and read its documents
 * 
 */
class FileStream{
    private:
    unsigned int lineCount = 0;
    std::string line;
    std::ifstream file;
    std::vector<std::string> dictionary;
    
    /**
     * @brief Load the next line of a file to the line variable
     * 
     */
    void loadLine(){
        char buffer[5000];
        file.getline(buffer,5000);
        line = buffer;
    }

    public:
    /**
     * @brief Get the next word from the stream
     * 
     * @return std::string 
     */
    std::string nextWord(){
        if(dictionary.size()<=lineCount)
            return "";
        std::string word = dictionary.at(lineCount);
        lineCount++;
        return word;
    }

    /**
     * @brief Get the next int value from the stream
     * 
     * @return int 
     */
    int nextInt(){
        std::string numBuffer = nextWord();
        return std::stoi(numBuffer.c_str());
    }

    /**
     * @brief Get the next float value from the stream
     * 
     * @return float 
     */
    float nextFloat(){
        std::string numBuffer = nextWord();
        return std::stof(numBuffer.c_str());
    }

    /**
     * @brief Get the next double value from the stream
     * 
     * @return double 
     */
    double nextDouble(){
        std::string numBuffer = nextWord();
        return std::stod(numBuffer.c_str());
    }

    /**
     * @brief Get the Dict object
     * 
     * @return std::vector<std::string> A string vector contaning all words in the file
     */
    std::vector<std::string> getDict(){
        return dictionary;
    }

    /**
     * @brief Construct a new File Stream object
     * 
     * @param fileName The name name of the file to be streamed
     */
    FileStream(std::string fileName ){
        std::ifstream aux;
        aux.open(fileName);
        while(!aux.eof()){
            char buffer[5000];
            aux.getline(buffer,5000);
            std::string ax = buffer;
            std::istringstream iss (ax);
            std::vector<std::string> results(std::istream_iterator<std::string>{iss},  std::istream_iterator<std::string>());
            for(auto& x : results){
                dictionary.push_back(x);
            }

        }
        aux.close();
        file.open(fileName);
    }

    /**
     * @brief Get the words from current line of the stream 
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> lineValues(){
        if(line.length()<1){
            if(file.eof())
                return std::vector<std::string> {""};
            loadLine();
        }
        std::istringstream iss (line);
        std::vector<std::string> results(std::istream_iterator<std::string>{iss},  std::istream_iterator<std::string>());
        lineCount +=results.size();
        loadLine();
        return results;
    }

	/**
	 * @brief Get the string until the delimiter
	 * 
	 * @param delim Delimiter character to stop reading, default is ','
	 * @return std::string 
	 */
	std::string getDelimiter(char delim=','){
		if(line.length()<1){
			if(file.eof())
				return "";
			loadLine();
		}
		std::string result = "";
		while(line.length()>0){
			if(line[0]==delim){
				line = line.substr(1);
				return result;
			}
			result+=line[0];
			line = line.substr(1);
		}
		return result;
	}
};