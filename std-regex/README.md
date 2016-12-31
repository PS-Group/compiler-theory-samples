# ������� ��� std::regex � id-scanners

## ������� ������������� ��������������� � �������� id-scanners

����� ��������� ��� �������, ��������������� ���������� ���������� ��������� � ������� STL.
���������� ��������� � STL ������������ ������� `std::regex` � ����������� ��������� � ��������� `<regex>`.
��� ������� ������� ������� �� boost.test.

### �������������� ��������������� (`IdMatcher.h`)

����� CIdMatcher �������� ������ � ���������, �������� �� ������ ������� ���������� ���������������.
��� ���������� ������ ������������ ������� [`std::regex_match`](http://www.cplusplus.com/reference/regex/regex_match/).

### ������� ������ ��������������� (`SimpleIdScanner.h`)

����� CSimpleIdScanner �������� ����� ��������� � ��������� �� ���� ��������������.
�� ����� ������� ��������������� ������ �������������� ���������������.
��� ���������� ������ ������������ ������� [`std::regex_seach`](http://www.cplusplus.com/reference/regex/regex_search/).

```cpp
std::regex_search(std::string::iterator begin,
                  std::string::iterator end,
                  std::smatch & match,
                  std::regex const& pattern)
```

### ���������� ������ ��������������� (`AdvancedIdScanner.cpp`)

� ������� �� �������� �������, ���������� ����� ������������ ����������� � ����� C: `/* it's comment */`.
��� ���������� ������ ����� ������������ ������� [`std::regex_seach`](http://www.cplusplus.com/reference/regex/regex_search/).

## ����������� ���������� ����� Dart � �������� dart-lexer

� �������� ��������� ����������� ���������� Dart, ����������� �� ���������� ����������. ��. ����� ��� �� ����� Dart �� [dartlang.org/guides/language/language-tour](https://www.dartlang.org/guides/language/language-tour)
