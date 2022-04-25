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
      std::string name {};
      std::cout << "Name to find: ";
      getline(std::cin, name);
      auto result = std::find_if(personnelBase_.begin(),
                     personnelBase_.end(),
                     [name](auto student){return student->getName() == name;});
      if (result == personnelBase_.end())
         return personnelBase_.front();
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
      auto deletedStudent = 
         std::remove_if(std::next(personnelBase_.begin()),
                        personnelBase_.end(),
                        [index](auto student){return student->getIndexNumber() == index;});
      personnelBase_.erase(deletedStudent, personnelBase_.end());
   }
   return personnelBase_;
}

bool University::pToF(){
   if(personnelBase_.size() == 1){
      std::cout << "The base is empty.\nChose again: ";
      return false;
   }
   std::string nameOfBase = getName() + "DataBase.txt";
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
   return true;
}

bool University::rFromF(){
   std::string nameOfBase = getName() + "DataBase.txt";
   std::ifstream input(nameOfBase);
   if (!input.is_open()){
      std::cerr << "Error!!!";
      return false;
   }  
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
   auto p = findByPESEL();
   if (p->getSalary() != "-1") {
      p->setSalary(newSalary);
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
   std::for_each(std::next(personnelBase_.begin()),
                 personnelBase_.end(),
                 [](auto e){if (e->getSalary() != "-1") {e->printPerson();}});
}

void University::printEmp(){
   std::for_each(std::next(personnelBase_.begin()),
                 personnelBase_.end(),
                 [](auto e){if (e->getIndexNumber() != "-1") {e->printPerson();}});
}