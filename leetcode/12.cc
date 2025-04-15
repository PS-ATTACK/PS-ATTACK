class Solution {
public:
    // Roman 단어는 큰수 부터 작은수로 left to right로 써진다.
    // 만약 반대의 경우에는 Substraction을 한다.
    // 반대 상황의 예: IV ( 1, 5) 이럴때는 4가 된다.
    string intToRoman(int num) {
        map<int, string>::reverse_iterator iter;
        for (iter = c.rbegin(); iter != c.rend(); iter++) {
            cout << iter->first << endl;
        }
        int m_num = num;
        int t_div = 1000;
        string result = "";
        while (t_div > 0) {

            cout << t_div << endl;
            if(m_num <= 0) break;

            int div = (m_num / t_div) * t_div; // 나눈 값 ex ) 3000
            if(div != 0){
                result += convertRoman(div);
                m_num = m_num - div;
            }

            cout << m_num << endl;
            t_div /= 10;
        }
        return result;
    }

private:
    map<int, string> c = {{1, "I"},   {5, "V"},   {10, "X"},  {50, "L"},
                          {100, "C"}, {500, "D"}, {1000, "M"}};
    map<int, string> m = {{4, "IV"},  {9, "IX"},   {40, "XL"},
                          {90, "XC"}, {400, "CD"}, {900, "CM"}};
    // 900 이거나 400 이면, CM OR CD
    // 90 이거나 40이면 , XC OR XL
    // 9거나 4면, IV ,  IX
    string convertRoman(int divNum) {
        cout << "here" << divNum << endl;
        string str = "";
        if (m.contains(divNum) == true) {
            return getReverseRoman(divNum);
        }

        map<int, string>::reverse_iterator iter;
        for (iter = c.rbegin(); iter != c.rend(); iter++) {
            cout << "her" << endl;
            if (divNum == 0)
                continue;
            if(divNum - iter->first >= 0){
                 int r = divNum / iter->first;
                for (int i = 0; i < r; i++) { // 몫 만큼 집어넣기
                    str += iter->second;
                }
                divNum -= (iter->first *
                                   r); // 나누었을때 0으로 나누어지므로 음수
                                       // 값이 아니라는 것이 증명이 된다 .
            }
        
        }
        return str;
    }
    string getReverseRoman(int num) { return m.find(num)->second; }
};