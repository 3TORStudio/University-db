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
   Student s("Zwirek",
             "Muchomorek",
             "M",
             std::make_shared<Address>("Bagienna","1","77-111","Brzezina"),
             "78040602656",
             "111A");
   
   personnelBase_.push_back(std::make_shared<Student>(s));
   return true;
}

void  University::printDb(){  
   std::for_each(std::next(personnelBase_.begin()),
                 personnelBase_.end(),
                 [](auto e){e->printPerson();});                
}

personDb const University::findByName(const std::string  & name){
   auto result = std::find_if(personnelBase_.begin(),
                  personnelBase_.end(),
                  [name](auto student){return student->getName() == name;});
   if (result == personnelBase_.end())
      return personnelBase_.front();
   return *result;
}

personDb const University::findByPESEL(const std::string & PESEL){
   auto result = std::find_if(std::next(personnelBase_.begin()),
                  personnelBase_.end(),
                  [PESEL](auto student){return student->getPESEL() == PESEL;});
   if (result == personnelBase_.end())
      return personnelBase_.front();
   return *result;
}

universityDb & University::sortByName(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getSurname() < secondStudent->getSurname();
   };
   std::sort(std::next(personnelBase_.begin()), personnelBase_.end(), comp);
   return personnelBase_;
}

universityDb & University::sortByPESEL(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getPESEL() < secondStudent->getPESEL();
   };
   std::sort(std::next(personnelBase_.begin()), personnelBase_.end(), comp);
   return personnelBase_;
}

universityDb & University::deleteById(std::string index){
   auto deletedStudent = 
      std::remove_if(std::next(personnelBase_.begin()),
                     personnelBase_.end(),
                     [index](auto student){return student->getIndexNumber() == index;});
   personnelBase_.erase(deletedStudent, personnelBase_.end());
   return personnelBase_;
}

bool University::pToF(){
   if(personnelBase_.size() == 1){
      std::cerr << "Database is empty!\n";
      return false;
   }
   std::ofstream output("UniversityDataBase.txt");
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
   std::ifstream input("UniversityDataBase.txt");
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
