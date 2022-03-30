#include "university.hpp"

University::University(std::string name): name_(name){
   Student s("No exist",
             "-",
             "-",
             std::make_shared<Address>("-","-","-","-"),
             "00000000000",
             "-");
   studentsDb_.push_back(std::make_shared<Student>(s));
}

bool University::add(std::shared_ptr<Student> student){
   studentsDb_.push_back(student);
   return true;
}

bool University::add(){
   Student s("Zwirek",
             "Muchomorek",
             "M",
             std::make_shared<Address>("Bagienna","1","77-111","Brzezina"),
             "78040602656",
             "111A");
   
   studentsDb_.push_back(std::make_shared<Student>(s));
   return true;
}

void  University::printDb(){  
   std::for_each(std::next(studentsDb_.begin()),
                 studentsDb_.end(),
                 [](auto e){e->printStudent();});                
}

studentDb const University::findByName(const std::string  & name){
   auto result = std::find_if(studentsDb_.begin(),
                  studentsDb_.end(),
                  [name](auto student){return student->getName() == name;});
   if (result == studentsDb_.end())
      return studentsDb_.front();
   return *result;
}

studentDb const University::findByPESEL(const std::string & PESEL){
   auto result = std::find_if(std::next(studentsDb_.begin()),
                  studentsDb_.end(),
                  [PESEL](auto student){return student->getPESEL() == PESEL;});
   if (result == studentsDb_.end())
      return studentsDb_.front();
   return *result;
}

universityDb & University::sortByName(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getSurname() < secondStudent->getSurname();
   };
   std::sort(std::next(studentsDb_.begin()), studentsDb_.end(), comp);
   return studentsDb_;
}

universityDb & University::sortByPESEL(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getPESEL() < secondStudent->getPESEL();
   };
   std::sort(std::next(studentsDb_.begin()), studentsDb_.end(), comp);
   return studentsDb_;
}

// universityDb & University::deleteById(std::string index){
//    auto deletedStudent = 
//       std::remove_if(std::next(studentsDb_.begin()),
//                      studentsDb_.end(),
//                      [index](auto student){return student->getIndexNumber() == index;});
//    studentsDb_.erase(deletedStudent, studentsDb_.end());
//    return studentsDb_;
// }

// bool University::pToF(){
//    if(studentsDb_.size() == 1){
//       std::cerr << "Database is empty!\n";
//       return false;
//    }
//    std::ofstream output("UniversityDataBase.txt");
//    if (output.fail()){
//       std::cerr << "Error!!!";
//       return false;
//    }
//    for(const auto  & e: studentsDb_){
//       output << e->getIndexNumber() << ';'
//              << e->getName() << ';'
//              << e->getSurname() << ';'
//              << e->getPESEL() << ';'
//              << e->getSex() << ';'
//              << e->getAddress()->getStreet() << ';'
//              << e->getAddress()->getHouseNumber() << ';'
//              << e->getAddress()->getPostalCode() << ';'
//              << e->getAddress()->getTown() << ';' << '\n';
//    }
//    return true;
// }

// bool University::rFromF(){
//    std::ifstream input("UniversityDataBase.txt");
//    if (!input.is_open()){
//       std::cerr << "Error!!!";
//       return false;
//    }  
//    studentsDb_.clear();
//    std::string line;

//    std::vector <std::string> vData;
//    while(std::getline(input,line)){
//       std::string temp;
//       for(const auto &e: line){        
//          if(e == ';'){
//             vData.push_back(temp);
//             temp.clear();
//             continue;
//          }
//          temp += e;
//       }
//       this->add(std::make_shared<Student>(vData[1],
//                                           vData[2],
//                                           std::make_shared<Address>(vData[5],
//                                                                      vData[6],
//                                                                      vData[7],
//                                                                      vData[8]),
//                                           vData[0],
//                                           vData[3],
//                                           vData[4]));
//       vData.clear();
//    } 
//    return true;
// }
