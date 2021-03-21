#include "PatternReader.h"

PatternReader::PatternReader()
    : m_line_ct(0)
{}

PatternReader::PCMD::set(char s, float value)
{
    {
        switch (s)
        {
            case "G":
                g = (int) value;
                break;
            case "X":
                x = value;
                break;
            case "Y":
                y = value;
                break;
            case "R":
                r = value;
                break;
            case "TH":
                th = value;
                break;
            default :
                throw std::invalid_argument("invalid key passed");
        }
    }
}

void PatternReader::get_file()
{

}

void PatternReader::get_file(std::string filename)
{
    std::ifstream file;
    file.open(filename, std::ios::in);
    std::string line;
    while (std::getline(file, line)) {
        m_file_cont->push_back(line);
    }
    file.close();
}

void PatternReader::clear_file() 
{
    m_file_cont->empty();
    m_line_ct = 0;
}

bool PatternReader::is_next()
{
    return m_line_ct < m_file_cont->size();
}

PatternReader::PCMD PatternReader::next()
{
    std::string line = m_file_cont[m_line_ct];
    m_line_ct ++;
    return read_line(line);
}

PatternReader::read_line(std::string line)
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
    PCMD res;
    flag_locs.push_back(line.size());
    std::vector<float> res;
    for (std::vector<int>::iterator it = flag_locs.begin() ; it != flag_locs.end()-1; ++it)
    {
        std::string sub = line.substr( (*it)+1, (*(it+1) - *it)-1 );
        char key = line[*it];
        res.set(key, std::stof(sub));
        // std::cout << *it << " - " << *(it+1) << std::endl;
        // std::cout << line[*it] << ": " << sub << std::endl;
        // std::cout << "cast to float: " << std::stof(sub)  << std::endl;
    }

}


