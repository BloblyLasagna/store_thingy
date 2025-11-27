#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf8"); // Чтобы нормально показывал русский в некоторых средах

    // Цены за 1 литровую банку (можно изменить по заданию препода)
    const double PRICE_APPLE        = 120.0; // яблочный
    const double PRICE_ORANGE       = 150.0; // апельсиновый
    const double PRICE_APRICOT      = 130.0; // абрикосовый
    const double PRICE_PEAR         = 110.0; // грушевый

    const double PRICE_TOMATO       = 90.0;  // томатный
    const double PRICE_ONION        = 80.0;  // луковый
    const double PRICE_CUCUMBER     = 70.0;  // огуречный

    const double PRICE_GARLIC_TEA   = 60.0;  // чесночный чай
    const double PRICE_PARSLEY_TEA  = 75.0;  // петрушевый чай

    // Порог "большой покупки" для скидки 13%
    // XXX из задания — можно поменять значение константы.
    const double BIG_PURCHASE_THRESHOLD = 1000.0; 

    // Кол-во в литровых банках
    int qApple, qOrange, qApricot, qPear;
    int qTomato, qOnion, qCucumber;
    int qGarlicTea, qParsleyTea;

    cout << "Добро пожаловать в магазин \"Соки Никиты\"!\n";
    cout << "Введите количество литров для каждого напитка (0 - не брать).\n\n";

    cout << "ФРУКТОВЫЕ СОКИ:\n";
    cout << "Яблочный (руб/л " << PRICE_APPLE << "): ";
    cin >> qApple;
    cout << "Апельсиновый (" << PRICE_ORANGE << "): ";
    cin >> qOrange;
    cout << "Абрикосовый (" << PRICE_APRICOT << "): ";
    cin >> qApricot;
    cout << "Грушевый (" << PRICE_PEAR << "): ";
    cin >> qPear;

    cout << "\nОВОЩНЫЕ СОКИ:\n";
    cout << "Томатный (" << PRICE_TOMATO << "): ";
    cin >> qTomato;
    cout << "Луковый (" << PRICE_ONION << "): ";
    cin >> qOnion;
    cout << "Огуречный (" << PRICE_CUCUMBER << "): ";
    cin >> qCucumber;

    cout << "\nЧАИ:\n";
    cout << "Чесночный чай (" << PRICE_GARLIC_TEA << "): ";
    cin >> qGarlicTea;
    cout << "Петрушевый чай (" << PRICE_PARSLEY_TEA << "): ";
    cin >> qParsleyTea;

    // ---- Подсчёт без скидок ----
    double appleSum       = qApple      * PRICE_APPLE;
    double orangeSum      = qOrange     * PRICE_ORANGE;
    double apricotSum     = qApricot    * PRICE_APRICOT;
    double pearSum        = qPear       * PRICE_PEAR;

    double tomatoSum      = qTomato     * PRICE_TOMATO;
    double onionSumRaw    = qOnion      * PRICE_ONION;   // до скидки "каждый 4-й литр"
    double cucumberSum    = qCucumber   * PRICE_CUCUMBER;

    double garlicTeaSum   = qGarlicTea  * PRICE_GARLIC_TEA;
    double parsleyTeaSum  = qParsleyTea * PRICE_PARSLEY_TEA;

    double totalWithoutDiscounts =
        appleSum + orangeSum + apricotSum + pearSum +
        tomatoSum + onionSumRaw + cucumberSum +
        garlicTeaSum + parsleyTeaSum;

    // ---- СКИДКА 1: 5% на петрушевый чай при покупке >= 3 л ----
    double parsleyTeaDiscount = 0.0;
    if (qParsleyTea >= 3) {
        parsleyTeaDiscount = parsleyTeaSum * 0.05; // 5%
    }
    double parsleyTeaAfter = parsleyTeaSum - parsleyTeaDiscount;

    // ---- СКИДКА 2: Каждый 4-й литр лукового сока в подарок ----
    // Каждый 4-й литр не оплачивается:
    int freeOnionLiters = qOnion / 4; // целая часть
    int paidOnionLiters = qOnion - freeOnionLiters;
    double onionSumAfter = paidOnionLiters * PRICE_ONION;
    double onionDiscount = onionSumRaw - onionSumAfter; // сумма "подарка"

    // ---- Сумма после товарных скидок ----
    double subtotalAfterItemDiscounts =
        appleSum + orangeSum + apricotSum + pearSum +
        tomatoSum + onionSumAfter + cucumberSum +
        garlicTeaSum + parsleyTeaAfter;

    // ---- СКИДКА 3: 13% на весь чек, если сумма > XXX ----
    double bigPurchaseDiscount = 0.0;
    if (subtotalAfterItemDiscounts > BIG_PURCHASE_THRESHOLD) {
        bigPurchaseDiscount = subtotalAfterItemDiscounts * 0.13; // 13%
    }

    double finalTotal = subtotalAfterItemDiscounts - bigPurchaseDiscount;

    cout << fixed << setprecision(2);
    cout << "\n------------------------------------------\n";
    cout << "Сумма без скидок: " << totalWithoutDiscounts << " руб.\n";

    cout << "Скидка за петрушевый чай (5% при >= 3 л): "
         << parsleyTeaDiscount << " руб.\n";

    cout << "Скидка за луковый сок (каждый 4-й литр в подарок): "
         << onionDiscount << " руб.\n";

    cout << "Сумма после товарных скидок: "
         << subtotalAfterItemDiscounts << " руб.\n";

    cout << "Скидка за большую покупку (13% при сумме > "
         << BIG_PURCHASE_THRESHOLD << " руб.): "
         << bigPurchaseDiscount << " руб.\n";

    cout << "------------------------------------------\n";
    cout << "ИТОГО К ОПЛАТЕ: " << finalTotal << " руб.\n";
    cout << "Спасибо за покупку в магазине \"Соки Никиты\"!\n";

    return 0;
}
