#include "university.hpp"

University::University(std::string name): name_(name){
   Employee s("No exist",
             "-",
             "-",
             std::make_shared<Address>("-","-","-","-"),
             "00000000000",
             "-");
   personnelBase_.push_back(std::make_shared<Employee>(s));
}

bool University::add(std::shared_ptr<Person> person){
   personnelBase_.push_back(person);
   return true;
}


bool University::add(){
   std::cout << "Chose 'e' for adding employee.\n";
   char a;
   std::cin >> a;
   if (a == 'e') {
      employeeDb p = getDataEmployee();
      personnelBase_.push_back(p);
   }
   else {
      studentDb p = getDataStudent();
      personnelBase_.push_back(p);
   }
   return true;
}

void  University::printDb(){  
   if (personnelBase_.size() == 1){
     std::cout << "The base is empty.\nChose again: ";
   }
   else{
      system("clear");
      std::for_each(std::next(personnelBase_.begin()),
                    personnelBase_.end(),
                    [](auto e){e->printPerson();});                
   }
   
}

personDb const University::findByName(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else{
      std::sort(personnelBase_.begin(),personnelBase_.end());
      std::string name {};
      std::cout << "Name to find: ";
      getline(std::cin, name);
      auto result = std::find_if(personnelBase_.begin(),
                     personnelBase_.end(),
                     [name](auto student){return student->getSurname() == name;});
      if (result == personnelBase_.end()){
         return personnelBase_.front();
      }
      universityDb tempList;
      std::copy_if(result,
                  personnelBase_.end(),
                  std::back_inserter<universityDb>(tempList),
                  [name](personDb p){return p->getSurname() == name;});
      
      for(auto e: tempList){
         e->printPerson();
      }

      return *result;
   }
   return nullptr;
}

personDb const University::findByPESEL(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      std::string PESEL {};
      getline(std::cin, PESEL);
      auto result = std::find_if(std::next(personnelBase_.begin()),
                     personnelBase_.end(),
                     [PESEL](auto student){return student->getPESEL() == PESEL;});
      if (result == personnelBase_.end())
         return personnelBase_.front();
      return *result;
   }
   return nullptr;
}

universityDb & University::sortByName(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      auto comp = [](auto firstStudent, auto secondStudent){
         return firstStudent->getSurname() < secondStudent->getSurname();
      };
      std::sort(std::next(personnelBase_.begin()), personnelBase_.end(), comp);
   }
   return personnelBase_;
}

universityDb & University::sortByPESEL(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      auto comp = [](auto firstStudent, auto secondStudent){
         return firstStudent->getPESEL() < secondStudent->getPESEL();
      };
      std::sort(std::next(personnelBase_.begin()), personnelBase_.end(), comp);
   }
   return personnelBase_;
}

universityDb & University::deleteById(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      std::string index;
      std::cout << "Index number to delete: ";
      getline(std::cin, index);
      
      //changing last character of index to upper 
      *index.rbegin() = std::toupper(*index.rbegin());

      auto result = std::find_if(std::next(personnelBase_.begin()),
                     personnelBase_.end(),
                     [index](auto student){return student->getIndexNumber() == index;});
      
      if(result == personnelBase_.end()){
         std::cout << "There is no such index.";
         return personnelBase_;
      }
      
      char answer = 'n';
      std::cout << "Do you really want do delete index " << index << " (y/n)? ";
      std::cin >> answer;
      answer = tolower(static_cast<int>(answer));
      if(answer != 'y'){
         return personnelBase_;
      }
      personnelBase_.erase(result);
   }
   return personnelBase_;
}

universityDb & University::deleteByPesel(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      std::string pesel;
      std::cout << "PESEL number to delete: ";
      getline(std::cin, pesel);

      auto result = std::find_if(std::next(personnelBase_.begin()),
                     personnelBase_.end(),
                     [pesel](auto student){return student->getPESEL() == pesel;});
      
      if(result == personnelBase_.end()){
         std::cout << "There is no such PESEL.";
         return personnelBase_;
      }
      
      char answer = 'n';
      std::cout << "Do you really want do delete PESEL" << pesel << " (y/n)? ";
      std::cin >> answer;
      answer = tolower(static_cast<int>(answer));
      if(answer != 'y'){
         return personnelBase_;
      }
      
      personnelBase_.erase(result);
   }
   return personnelBase_;
}

bool University::pToF(){
   if(personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
      return false;
   }
   std::string nameOfBase = getName() + ".ud";
   std::ofstream output(nameOfBase);
   if (output.fail()){
      std::cerr << "Error!!!";
      return false;
   }
   for(const auto  & e: personnelBase_){
      output << e->getName() << ';'
             << e->getSurname() << ';'
             << e->getSex() << ';'
             << e->getAddress()->getStreet() << ';'
             << e->getAddress()->getHouseNumber() << ';'
             << e->getAddress()->getPostalCode() << ';'
             << e->getAddress()->getTown() << ';'
             << e->getPESEL() << ';'
             << e->getIndexNumber() << ';' << '\n';
   }
   std::cout << "Done.\n";
   return true;
}

bool University::rFromF(){
   // listening data base files
   const std::filesystem::path pathToShow = std::filesystem::current_path();
   
   std:: vector<std::string> listOfFiles;
   for (const auto& entry : std::filesystem::directory_iterator(pathToShow)) {
      const std::string filenameStr = entry.path().filename().string();
      if (entry.is_regular_file() && 
          filenameStr.find(".ud") != std::string::npos) {
          listOfFiles.push_back(filenameStr);
      }
   }
   if (listOfFiles.empty()){
      std::cout << "There is no data base files.\n";
      return false;
   }
   std::copy(listOfFiles.begin(),
             listOfFiles.end(),
             std::ostream_iterator<std::string>(std::cout,"\n"));
   //
   std::string nameOfBase {};
   std:: cout << "Input the name of file to read: ";
   std:: cin >> nameOfBase;
   if(nameOfBase.size() < 3 || nameOfBase.substr(nameOfBase.size()-3,3) != ".ud"){
      nameOfBase += ".ud";
   }
   std::ifstream input(nameOfBase);
   if (!input.is_open()){
      std::cout << "File opening error!!!\n";
      return false;
   }
   nameOfBase.erase(nameOfBase.size()-3,3);
   setName(nameOfBase);  
   personnelBase_.clear();
   std::string line;

   std::vector <std::string> vData;
   while(std::getline(input,line)){
      std::string temp;
      for(const auto &e: line){        
         if(e == ';'){
            vData.push_back(temp);
            temp.clear();
            continue;
         }
         temp += e;
      }
      this->add(std::make_shared<Student>(vData[0],
                                          vData[1],
                                          vData[2],
                                          std::make_shared<Address>(vData[3],
                                                                     vData[4],
                                                                     vData[5],
                                                                     vData[6]),
                                          vData[7],
                                          vData[8]));
                                          
      vData.clear();
   }
   std::cout << "Done.\n";
   return true;
}

studentDb University::getDataStudent(){
   std::vector<std::string> vS {"First name: ",
                              "Last name: ",
                              "Index number: ",
                              "Street: ",
                              "House number: ",
                              "Postal code: ",
                              "City: ",
                              "PESEL: ",
                              "Sex: "};
   std::vector<std::string> vSa;

   std::transform(vS.begin(),
                  vS.end(),
                  std::back_inserter(vSa),
                  [](std::string q){std::cout << q; std::string a; std::cin >> a; return a;});
   
   return std::make_shared<Student>(vSa[0],
                                    vSa[1],
                                    vSa[8],
                                    std::make_shared<Address>(vSa[3],vSa[4],vSa[5],vSa[6]),
                                    vSa[7],
                                    vSa[2]);
}

employeeDb University::getDataEmployee(){
   std::vector<std::string> vS {"First name: ",
                              "Last name: ",
                              "Salary: ",
                              "Street: ",
                              "House number: ",
                              "Postal code: ",
                              "City: ",
                              "PESEL: ",
                              "Sex: "};
   std::vector<std::string> vSa;

   std::transform(vS.begin(),
                  vS.end(),
                  std::back_inserter(vSa),
                  [](std::string q){std::cout << q; std::string a; std::cin >> a; return a;});
   
   return std::make_shared<Employee>(vSa[0],
                                    vSa[1],
                                    vSa[8],
                                    std::make_shared<Address>(vSa[3],vSa[4],vSa[5],vSa[6]),
                                    vSa[7],
                                    vSa[2]);
}

void University::salaryModificationByPesel(const std::string & pesel, const std::string & newSalary){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   } 
   else {
      auto p = findByPESEL();
      if (p->getSalary() != "-1") {
         p->setSalary(newSalary);
      }
   }
}

universityDb & University::sortBySalary(){
   if (personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
   }
   else {
      auto comp = [](auto firstPerson, auto secondPerson){
         return firstPerson->getSalary() < secondPerson->getSalary();
      };
      std::sort(std::next(personnelBase_.begin()), personnelBase_.end(), comp);
   }
   return personnelBase_;
}

void University::printSt(){
   if (personnelBase_.size() == 1){
     std::cout << "The base is empty.\nChose again: ";
   }
   else{
      system("clear");
      std::for_each(std::next(personnelBase_.begin()),
                    personnelBase_.end(),
                    [](auto e){if (e->getIndexNumber() != "none") {e->printPerson();}});
   }
}

void University::printEmp(){
   if (personnelBase_.size() == 1){
     std::cout << "The base is empty.\nChose again: ";
   }
   else{
      system("clear");
      std::for_each(std::next(personnelBase_.begin()),
                    personnelBase_.end(),
                    [](auto e){if (e->getSalary() != "none") {e->printPerson();}});
   }
}

void University::generateData(){
   auto dg = std::make_unique<DataGenerator>();
   std::random_device ranDev;
   std::mt19937 ranEngine(ranDev());
   
   std::uniform_int_distribution<short> isEmployee(0,1);
   
   std::cout << "How many records to generate? ";
   unsigned numOfRecords = 0;
   std::cin >> numOfRecords;

   for(size_t i = 0; i < numOfRecords; ++i){
      std::string sex = dg->generateSex();
      std::string name {};
      std::string surname {};
      
      if (sex == "F"){
         name = dg->generateName(dg->getSource(1));
         surname = dg->generateName(dg->getSource(2)); 
      }
      if (sex == "M"){
         name = dg->generateName(dg->getSource(3));
         surname = dg->generateName(dg->getSource(4)); 
      }
      std::string pesel = dg->generatePesel(sex);
      std::string indexNumber = dg->generateIndexNumber();
      std::string salary = dg->generateSalary();
      
      if (isEmployee(ranDev)){
         add(std::make_shared<Employee>(name,
            surname,
            sex,
            dg->generateAddress(),
            pesel,
            salary));
      }
      else {
         add(std::make_shared<Student>(name,
            surname,
            sex,
            dg->generateAddress(),
            pesel,
            indexNumber));
      }
   }
   std::cout << "Done.\n";
   std::cin.ignore(); std::cin.clear();
}

void University::setName(std::string name){
   name_ = name;
}

int University::getNumberOfPeople(){
   return personnelBase_.size() - 1;
}