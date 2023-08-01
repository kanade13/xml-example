#include <iostream>
#include <tinyxml.h>

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("D:\\dev\\xmltest\\test.xml")) {
        std::cout << "Error loading XML file: " << doc.ErrorDesc() << std::endl;
        return 1;
    }

    TiXmlElement* root = doc.RootElement();
    if (!root) {
        std::cout << "Error: No root element found in XML file!" << std::endl;
        return 1;
    }

    TiXmlElement* name = root->FirstChildElement("name");
    if (!name) {
        std::cout << "Error: No <name> element found in XML file!" << std::endl;
        return 1;
    }
    std::cout << "Value of <name>: " << name->GetText() << std::endl;

    /*TiXmlNode* node = root->FirstChild();
    const char* nameValue = node->ToElement()->GetText();
    std::cout << nameValue << std::endl;*/
    
    //注释掉的这一段并不会按希望的那样输出kanade，而是卡掉了
    //firstchild应该是并没有访问到元素节点，而是访问到属性节点去了，而属性节点可能不能转换为element，所以失败
    //注意只是可能的解释，我也不清楚，反正以后碰到再说

    TiXmlElement* Name = name->NextSiblingElement("Name");
    if (!Name) {
        std::cout << "Error: No <Name> element found in XML file!" << std::endl;
        return 1;
    }
    
    
    std::cout << "Value of <Name>: " << Name->GetText() << std::endl;

    return 0;
}
