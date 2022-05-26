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

std::string DataGenerator::generateName(const std::string & src){  
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

  time_t t = time(NULL);
  t -= interval;
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
   

   short numPesel = num(ranEngine);
   if(numPesel < 10){
      peselData += "00" + std::to_string(numPesel);
   }
   else if (numPesel < 100){
      peselData += "0" + std::to_string(numPesel);
   }
   else{
      peselData += std::to_string(numPesel);

   }

   short number = sexN(ranEngine);
   
   std::string numSex {};
   if(sex == "F" && number != 0){
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
      else if (number == 0) {
         numSex = std::to_string(number + 1);
      }
      else {
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
   
   auto controlNum = s % 10 == 0 ? "0" : std::to_string(10 - (s % 10));

   peselData += controlNum;

   return peselData;
}

std::string DataGenerator::generateIndexNumber(){
   std::uniform_int_distribution<short> ranNum(1,100);
   std::uniform_int_distribution<short> ranLetter(65,90);

   std::string indexNumber {};
   short number = ranNum(ranEngine);
   if(number < 10){
      indexNumber = "00" + std::to_string(number); 
   }
   else if (number < 100){
      indexNumber = "0" + std::to_string(number);
   }
   else {
      indexNumber = std::to_string(number);
   }
   indexNumber += static_cast<char>(ranLetter(ranEngine));
   return indexNumber;
}

std::string DataGenerator::generateSalary(){
   std::uniform_int_distribution<int> randomSalary(3200,10000);
   return std::to_string(randomSalary(ranEngine));
}

std::shared_ptr<Address> DataGenerator::generateAddress(){
   // street
   std::ifstream input("../streets.txt");
   if (!input.is_open()){
      std::cout << "Can't open\n";
   }
   std::uniform_int_distribution<int> numOfStreets(1,countLinesInFile("../streets.txt"));
   unsigned line = numOfStreets(ranEngine);
   unsigned counter = 0;

   std::string street{};
   while(counter != line){
      getline(input,street);
      counter++;
   }
   input.close();

   // house number
   std::uniform_int_distribution<int> kindOfHouse(0,1);
   std::uniform_int_distribution<int> houseNum(1,100);
   std::uniform_int_distribution<int> flatNumber(1,150);


   std::string houseNumber = kindOfHouse(ranEngine)
                           ? std::to_string(houseNum(ranEngine))
                           : std::to_string(houseNum(ranEngine)) + "/" + std::to_string(flatNumber(ranEngine));
   
   // postal code
   input.open("../postalCodes.txt");
   if (!input.is_open()){
      std::cout << "Can't open\n";
   }
   std::uniform_int_distribution<int> numOfPostalCodes(1,countLinesInFile("../postalCodes.txt"));
   line = numOfPostalCodes(ranEngine);
   counter = 0;
   
   std::string postalCode{};
   std::string town{};
   while(counter != line){
      input >> postalCode >> town;
      counter++;
   }

   Address a (street,houseNumber,postalCode,town);

   return std::make_shared<Address>(a);
}