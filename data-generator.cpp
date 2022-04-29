#include "data-generator.hpp"

std::string DataGenerator::getMaleName(){
   std::random_device ranDev;
   std::mt19937 ranEngine(ranDev());
   std::uniform_int_distribution<int> numOfNames(1,countLinesInFile("male-names.txt"));
   //std::uniform_int_distribution<int> numOfNames(1,5);
   unsigned line = numOfNames(ranEngine);
   unsigned counter = 0;
   std::ifstream in("../firstNames.txt");
   if (!in.is_open()){
      std::cerr << "Can't open\n";
   }
   std::string name{};
   while(counter != line){
      getline(in,name);
      counter++;
   }
   return name;
}

int DataGenerator::countLinesInFile(const std::string & fileName){
   std::string src = "../" + fileName;
   std::ifstream input(src);
   size_t numOfLines = 0;
   std::string unused{};
   while(getline(input,unused)){
      if(!unused.empty()){
         ++numOfLines;
      }
   }
   return numOfLines;
}