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
    
    //ע�͵�����һ�β����ᰴϣ�����������kanade�����ǿ�����
    //firstchildӦ���ǲ�û�з��ʵ�Ԫ�ؽڵ㣬���Ƿ��ʵ����Խڵ�ȥ�ˣ������Խڵ���ܲ���ת��Ϊelement������ʧ��
    //ע��ֻ�ǿ��ܵĽ��ͣ���Ҳ������������Ժ�������˵

    TiXmlElement* Name = name->NextSiblingElement("Name");
    if (!Name) {
        std::cout << "Error: No <Name> element found in XML file!" << std::endl;
        return 1;
    }
    
    
    std::cout << "Value of <Name>: " << Name->GetText() << std::endl;

    return 0;
}
