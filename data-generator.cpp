#include "data-generator.hpp"

std::random_device ranDev;
std::mt19937 ranEngine(ranDev());

std::string DataGenerator::generateSex(){
      std::uniform_int_distribution<int> genSex(0,1);
      std::string sex = genSex(ranEngine) == 0 ? "F" : "M";
      return sex;
}

std::string DataGenerator::getSource(const std::string & sex, const short & num){
   
   
}

std::string DataGenerator::getMaleName(){  
   std::uniform_int_distribution<int> numOfNames(1,countLinesInFile("../male-names.txt"));
   //std::uniform_int_distribution<int> numOfNames(1,5);
   unsigned line = numOfNames(ranEngine);
   unsigned counter = 0;
   std::ifstream in("../male-name.txt");
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

std::string DataGenerator::getFemaleName(){  
   std::uniform_int_distribution<int> numOfNames(1,countLinesInFile("female-names.txt"));
   //std::uniform_int_distribution<int> numOfNames(1,5);
   unsigned line = numOfNames(ranEngine);
   unsigned counter = 0;
   std::ifstream in("../female-names.txt");
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

std::string DataGenerator::getMaleSurname(){  
   std::uniform_int_distribution<int> numOfNames(1,countLinesInFile("male-surnames.txt"));
   //std::uniform_int_distribution<int> numOfNames(1,5);
   unsigned line = numOfNames(ranEngine);
   unsigned counter = 0;
   std::ifstream in("../male-surname.txt");
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
   if (!input.is_open()){
      std::cerr << "Can't count lines.";
      return 0;
   }
   size_t numOfLines = 0;
   std::string unused{};
   while(getline(input,unused)){
      if(!unused.empty()){
         ++numOfLines;
      }
   }
   return numOfLines;
}