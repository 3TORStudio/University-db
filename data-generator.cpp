#include "data-generator.hpp"

std::random_device ranDev;
std::mt19937 ranEngine(ranDev());

std::string DataGenerator::generateSex(){
      std::uniform_int_distribution<int> genSex(0,1);
      std::string sex = genSex(ranEngine) == 0 ? "F" : "M";
      return sex;
}

std::string DataGenerator::getSource(const short & num){
   switch(num){
      case 1:
      return "../female-names.txt";
      case 2:
      return "../female-surnames.txt";
      case 3:
      return "../male-names.txt";
      case 4:
      return "../male-surnames.txt";
   }
   return "";
}

std::string DataGenerator::getData(const std::string & src){  
   std::uniform_int_distribution<int> numOfNames(1,countLinesInFile(src));
   unsigned line = numOfNames(ranEngine);
   unsigned counter = 0;
   std::ifstream in(src);
   if (!in.is_open()){
      std::cerr << "Can't open\n";
   }
   std::string data{};
   while(counter != line){
      getline(in,data);
      counter++;
   }
   return data;
}

int DataGenerator::countLinesInFile(const std::string & src){
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

std::string DataGenerator::generatePesel(const std::string & sex){
   std::uniform_int_distribution<time_t> ran(100000,3000000000);
   std::uniform_int_distribution<short> num(1,999);
   std::uniform_int_distribution<short> sexN(0,9);
   

  unsigned interval = ran(ranEngine);

  //std::cout << interval << '\n';
  
  time_t t = time(NULL);
  //std::cout << asctime(localtime(&t)) << '\n';
  t -= interval;
  std::cout << asctime(localtime(&t)) << '\n';
  auto date = gmtime(&t); 
  std::string year = std::to_string(date->tm_year + 1900);
  std::string month = std::to_string(date->tm_mon + 1);
  std::string day = std::to_string(date->tm_mday);
  std::string peselData = year.substr(2,2)
                         + ((date->tm_year + 1900 >= 2000) 
                              ? std::to_string(date->tm_mon + 1 + 20) 
                              : (date->tm_mon < 9 
                                 ? "0" + month 
                                 : std::to_string(date->tm_mon + 1))) 
                         + (date->tm_mday < 10 ? "0" + day : day);
   
   auto numPesel = std::to_string(num(ranEngine));
   peselData += numPesel;

   short number = sexN(ranEngine);
   std::string numSex {};
   if(sex == "F"){
      if(number % 2){
         numSex = std::to_string(number - 1);
      }
      else{
         numSex = std::to_string(number);
      }
   }
   else{
      if(number % 2){
         numSex = std::to_string(number);
      }
      else{
         numSex = std::to_string(number - 1);
      }
   }
   peselData += numSex;

   unsigned s = peselData[0] -'0'
               + (peselData[1] - '0') * 3
               + (peselData[2] - '0') * 7
               + (peselData[3] - '0') * 9
               + peselData[4] -'0'
               + (peselData[5] - '0') * 3
               + (peselData[6] - '0') * 7
               + (peselData[7] - '0') * 9
               + peselData[8] -'0'
               + (peselData[9] - '0') * 3;
   auto controlNum = s % 10 == 0 ? std::to_string(0) : std::to_string(10 - (s % 10));
   peselData += controlNum;
   
   return peselData;
}