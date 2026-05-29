#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  std::string about;
  int age;
  int size() { return first_name.size() + last_name.size() + about.size() + sizeof(age); }
};

void PrintPersonName(Person p) {
  std::cout << "Full name: " << p.first_name + " " + p.last_name << std::endl;
}

void PrintPersonNameUsingReference(Person &p) {
  std::cout << "Full name: " << p.first_name + " " + p.last_name << std::endl;
}

void PrintPersonNameUsingReferenceConst(const Person &p) {
  std::cout << "Full name: " << p.first_name + " " + p.last_name << std::endl;
}

int main() {
  Person p;
  p.first_name = "Tommy";
  p.last_name = "Trojan";
  p.about =
      "Tommy Trojan, officially known as the Trojan Shrine, is one of the most "
      "recognizable figures of school pride at the University of Southern "
      "California. The life-size bronze statue of a Trojan warrior stands in "
      "the center of campus and serves as a popular meeting spot, as well as a "
      "centerpiece for a number of campus events. It is the most popular "
      "unofficial mascot of the university. The Trojan Shrine was sculpted by "
      "Roger Noble Burnham, who used USC football players such as Russ "
      "Saunders, Ernie Pinckert Henry Becker, Larry Stevens and John Ward as "
      "visual references for the statue.[1] It was unveiled during the "
      "University's 50th Jubilee in 1930. It cost $10,000 to build, after "
      "which a $1 surcharge was added onto the season football tickets in "
      "order to help offset this cost. The statue was created by Harold C. "
      "Swartz, a noted sculptor. Swartz exhibited extensively beginning in the "
      "early 1920s. He participated in all the major fine art exhibitions in "
      "Southern California and won many prizes. He was a member of the "
      "Sculptors Guild of Southern California and the California Art Club. "
      "Swartz had a solo exhibition at the Los Angeles County Museum of Art in "
      "1923. He exhibited at the Art Institute of Chicago in 1925 and 1929. "
      "Swartz designed several fountains for Hollywood celebrities, most "
      "notably Mary Pickford and Douglas Fairbanks. Large bronze sculptures "
      "were the centerpieces of these fountains. Swartz, like many artists in "
      "Los Angeles, did work for movie studios, including MGM. In many "
      "newspaper articles published around the end of World War II, Swartz is "
      "credited with the creation of the Oscar. This is disputed by all other "
      "historical sources. However, Swartz’s student George Stanley is "
      "officially credited with the design of the Oscar. Nonetheless, the "
      "style and technique of the Oscar is very similar to many of Swartz’s "
      "sculptures. His work “Dans Macabre” resembles the “Oscar.” This work "
      "was exhibited at the Art Institute of Chicago in 1929 and a facsimile "
      "appears in a 1931 film called “Scandal Sheet. Swartz was purely a "
      "modernist. He abstracted his subjects, employing cubist elements that "
      "were mildly surreal and often allegorical. Swartz’s works were received "
      "with great critical acclaim. He was also successful at executing "
      "realistic busts of well-known public figures, including Von Kliensmid, "
      "the president of the University of Southern California. He won a "
      "commission to create a bust of Theodore Roosevelt, which was located a "
      "local high school. Swartz also executed “Tommy Trojan,” a monumental "
      "sculpture of a Trojan warrior on the University of Southern California "
      "campus. The original name suggested for the statue was The Spirit of "
      "Troy, but that name went to the school's marching band.[2] On August "
      "17, 2017, during the USC village grand opening, the Hecuba, Queen of "
      "Troy statue was unveiled to the public. This large statue serves as the "
      "female counterpart to Tommy Trojan and represents the Women of USC.";

  std::cout << "p.size(): " << p.size() << std::endl;
  PrintPersonName(p);
  PrintPersonNameUsingReference(p);
  
  return 0;
}