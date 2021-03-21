
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>

// #include ""


void read(std::string filename)
{
    std::ifstream file;
    file.open(filename, std::ios::in);
    std::string line;

    while (std::getline(file, line)) {
        // file >> ch;
        // if (file.eof())
        //     break;

        std::cout << line << std::endl;
    }
    file.close();
}

void read_line_gcd(std::string line)
{
    std::vector<int> flag_locs;
    const std::string m_flags[] = {"G", "X", "Y", "R", "T"};
    for(const std::string f : m_flags)
    {   
        std::size_t temp = line.find(f);
        if(temp != std::string::npos)
        {
            for (int i=0; i<flag_locs.size()+1; i++)
            {
                if(i >= flag_locs.size()){
                    flag_locs.insert(flag_locs.end(), temp);
                    break;
                }
                if(temp < flag_locs[i])
                {
                    flag_locs.insert(flag_locs.begin()+i, temp);
                    break;
                }
            }
        }
    }
    flag_locs.push_back(line.size());
    std::vector<float> res;
    for (std::vector<int>::iterator it = flag_locs.begin() ; it != flag_locs.end()-1; ++it)
    {
        std::string sub = line.substr( (*it)+1, (*(it+1) - *it)-1 );
        std::cout << *it << " - " << *(it+1) << std::endl;
        std::cout << line[*it] << ": " << sub << std::endl;
        std::cout << "cast to float: " << std::stof(sub)  << std::endl;
    }
}

void read_line_thr(std::string line)
{
    std::vector<std::string> nums;
    int start = -1;
    for(int i=0; i<line.size(); i++)
    {
        if(line.at(i) == ' ')
        {
            if(start > -1) 
            {
                nums.push_back(line.substr( start, i-start ));
                start = -1;
            }
        }
        else if(line.at(i) == '#')
        {
            break;
        }
        else
        {
            if(start == -1)
            {
                start = i;
            }
        }
    }
    if(start > -1){
        nums.push_back(line.substr( start, line.size()-start ));
    }
    // std::cout << nums.size() <<std::endl;
    for(int i=0; i<nums.size(); i++)
    {
        std::cout << nums.at(i) << '|' << std::endl;
    }
}

int main() 
{
    // read("../patterns/sandify.gcode");
    std::string c = "G01 X5.66 T 567 Y32.6";
    std::string t = "  1.57080 0.01414 8.2934  ";
    std::cout << "starting reader" << std::endl;
    read_line_thr(t);

    return 0;
}