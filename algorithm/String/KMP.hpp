/**
 *  クヌース・モリス・プラット法
 *  単一パターン検索
 */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class KMP {
    T pattern_;
    vector<int> shift_table_;

public:
    /**
     *  探したい文字列から再開位置を知る表を作成する
     */
    KMP(const T& pattern) : pattern_(pattern)
    {
        int pattern_len = pattern_.size();
        shift_table_.resize(pattern_len + 1);

        constexpr int NIL = -1;
        shift_table_[0] = NIL;  // 最初はずらすことができないので NIL
        for (int i = 0, j = NIL; i < pattern_len; ++i) {
            while (j != NIL && pattern_[i] != pattern_[j]) {
                j = shift_table_[j];
            }
            shift_table_[i + 1] = ++j;  // 次どこから始めるかを記録
        }
    }

    /**
     *  探したい文字列 ( pattern ) が 与えられた文字列 ( text ) の中の
     *  どこの位置にあるのか検索する
     */
    vector<int> Match(const string& text)
    {
        int text_len = text.size();
        int pattern_len = pattern_.size();
        vector<int> result;
        for (int i = 0, k = 0; i < text_len; ++i) {
            while (k >= 0 && text[i] != pattern_[k]) {
                k = shift_table_[k];
            }
            if (++k >= pattern_len) {  // 一致したら text の始まりのidxを格納
                result.push_back(i - pattern_len + 1);
                k = shift_table_[k];
            }
        }
        return result;
    }
};
