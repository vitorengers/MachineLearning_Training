// #include <iterator>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <string>
// #include <string_view>


// class CSVRow
// {
// public:
//     std::string_view operator[](std::size_t index) const
//     {
//         return std::string_view (&m_line[m_data[index] + 1], m_data[index + 1] -  (m_data[index] + 1));
//     }
//     std::size_t size() const;
//     void readNextRow(std::istream& str);


//     std::istream& operator>>(std::istream& str, CSVRow& data)
//     {
//         data.readNextRow(str);
//         return str;
//     } 
    
// private:
//     std::string         m_line;
//     std::vector<int>    m_data;
// };
