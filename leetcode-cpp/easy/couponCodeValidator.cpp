#include <bits/stdc++.h>
using namespace std;

vector<string> validateCoupons(
    vector<string> &code,
    vector<string> &businessLine,
    vector<bool> &isActive)
{
    vector<string> result;
    vector<string> category = {"electronics", "grocery", "pharmacy", "restaurant"};

    // map each category to its order index for sorting
    unordered_map<string, int> categoryOrder;
    for (int i = 0; i < category.size(); i++)
    {
        categoryOrder[category[i]] = i;
    }
    // valid coupons
    vector<pair<string, string>> validCoupons;
    // regex to validate coupons
    regex validCodeRegex("^[A-Za-z0-9_]+$");

    // each coupon
    for (int i = 0; i < code.size(); i++)
    {
        // check if
        // code is not empty
        // code matches in regex
        // businessLine is in valid categories
        // isActive is true
        if (!code[i].empty() && regex_match(code[i], validCodeRegex) &&
            categoryOrder.count(businessLine[i]) && isActive[i])
        {
            validCoupons.emplace_back(businessLine[i], code[i]);
        }
    }

    // sort valid coupons using custom comparator, first by bsinessline then code
    sort(validCoupons.begin(), validCoupons.end(), [&](const auto &a, const auto &b)
         {
        if (categoryOrder[a.first] != categoryOrder[b.first])
        return categoryOrder[a.first] < categoryOrder[b.first];
    return a.second < b.second; });

    // extract only coupon codes from sorted list

    for (const auto &c : validCoupons)
    {
        result.push_back(c.second);
    }

    return result;
}

int main()
{
    /*
    You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

    code[i]: a string representing the coupon identifier.
    businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active.
    A coupon is considered valid if all of the following conditions hold:

    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.
    Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.
    */

    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};

    vector<string> res = validateCoupons(code, businessLine, isActive);

    for (const string &c : res)
    {
        cout << c << " ";
    }

    return 0;
}