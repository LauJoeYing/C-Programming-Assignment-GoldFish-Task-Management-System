#include "userDataInjection.h"

const int DATA_SIZE = 46;

const char emailList[46][50] = {
    "joeying0712@gmail.com", "leon88@yahoo.com", "charles0304@gmail.com", "law89aaron@hotmail.com", "zanlam@gmail.com", "rayrussel36@yahoo.com", "dawn84@yahoo.com", 
    "addy8550@gmail.com", "idellwolf16@yahoo.com", "sarh.amjd@yahoo.com", "travon58@gmail.com", "brent24@hotmail.com", "dana57@gmail.com", "monserrat73@gmail.com",
    "tessie2@yahoo.com", "gracie76@yahoo.com", "jovani81@hotmail.com", "tara87@hotmail.com", "zydfarwq77@yahoo.com", "Jovani81@hotmail.com", "viviantan@gmail.com",
    "stephen1996@yahoo.com", "leon88@yahoo.com", "charles0304@gmail.com", "law89aaron@hotmail.com", "zanlam@gmail.com", "rayrussel36@yahoo.com", "dawn84@yahoo.com",
    "addy8550@gmail.com", "idellwolf16@yahoo.com", "sarh.amjd@yahoo.com", "travon58@gmail.com", "brent24@hotmail.com", "dana57@gmail.com", "monserrat73@gmail.com",
    "tessie2@yahoo.com", "gracie76@yahoo.com", "jovani81@hotmail.com", "tara87@hotmail.com", "zydfarwq77@yahoo.com", "wiley_mohr87@gmail.com", "ceceliecelia@yahoo.com",
    "ester81@hotmail.com", "abeeeeee@gmail.com", "karina991@yahoo.com", "ginarenata@gmail.com"
};

const char nameList[46][50] = {
    "LAU JOE YING", "RAMESH NIJHAR", "QUAK SOON BEN", "ZAHARAH NORAZIM BINTI FARHAN", "KANDIAH SAMBANTHAN A/L DAIRIAM", "WONG BOW LE", "MOHAMED SYED KASIM BIN WAN YAZID",
    "NUR JULIA DANEAL BINTI IZZAT", "LEE PEI JUN", "NOOR AYUNI BINTI NAZAR", "GAVIN YEOW QI SHEK", "SHANTI GOUNDAR", "NUR HJH HASMALINDA BINTI NIK HAQIM", "CHEONG XIN YEE", 
    "JOEY KHAW KE XIN", "MOHAMAD ALILAH SEDEK BIN HAFIZI", "ONG KIANG JEE", "KO LING FUNG", "ROSE LAU GEE YAN", "MAH YUN QIAN", "VIVIAN TAN", "STEPHEN BENNET", "LEON HEW",
    "CHARLES HOWARD", "AARON LAW", "CHEN ZAN LAM", "SUAIDAH BINTI WAN KASIM ZAFRAN", "CHOW ZEE HA", "ADDY THUN SUAN SIAU", "MUHAMAD HAIZAN BIN FITRI", "JANAKY LAKSHMI A/L MANJIT",
    "JIE BO HOU", "SAM ZI JIA", "ANG ZHI LUK", "KUNDAN LAL NAGARAJ A/L JASSAL", "RACHEL MAH WEI SIU", "ELAINE OON SUN", "ALEYA AZRAAI", "NOOR HAFIEZA ALBUKHARY",
    "NUR ALYA MALIKI BINTI DZULLUTFI", "MOHD EHZA NORAZAM", "CECELIE EMIRA", "YEWANDE ESTER", "ABESSA DERORIT", "KARINA RUTH", "RENATA GINA"
};

const char usernameList[46][21] = {
    "ADMIN1", "ADMIN2", "ADMIN3", "ADMIN4", "ADMIN5", "ADMIN6", "ADMIN7", "ADMIN8", "ADMIN9", "ADMIN10", "ADMIN11", "ADMIN12", "ADMIN13", "ADMIN14", "ADMIN15", "ADMIN16",
    "ADMIN17", "ADMIN18", "ADMIN19", "ADMIN20", "vivian2002", "sb9101", "hew88leon", "charles1980", "aaronnn00", "zanlamchen", "rosie99", "CHOW1158", "atss723529",
    "haizan1996", "ja66naky", "jie9981", "sam56zijia", "angzhiluk", "kundanhaha", "EmelyBeloved03", "elaineoon77", "aleyaaaaaa", "hafieza38", "alyahappy", "ehza1982",
    "cecelie93", "ester1981yew", "abessaxx95", "ruth06ruth", "ginaaaa94xx"
};

const char passwordList[46][21] = {
    "ADMIN001", "ADMIN002", "ADMIN003", "ADMIN004", "ADMIN005", "ADMIN006", "ADMIN007", "ADMIN008", "ADMIN009", "ADMIN010", "ADMIN011", "ADMIN012", "ADMIN013", 
    "ADMIN014", "ADMIN015", "ADMIN016", "ADMIN017", "ADMIN018", "ADMIN019", "ADMIN020", "vivian123", "dWhuD8wcCt", "FS66P9CfPZ", "Dcy99NSNTS", "UBZXe8SATy",
    "x42nVvbX7x", "D9RAbkaCn9", "rCxmETGvuC", "ZEFYEh7C9V", "gAL6rWqFFH", "JW6BWkuFAt", "ArJVbRW7zz", "h3W83vW8QQ", "ujpUpjUWm7", "jVM7kpgGzC", "ucDxkKzxmF",
    "8f72t78kfV", "jnG29CWSYs", "wyFgB2UYfB", "wM9fx5k2LB", "Gz4g5jAtD6", "bhbRmuyZnW", "Skqdwhga3v", "KytjbX5wCm", "sjawAuukPV", "TSpMK3Tx8a"
};

const char contactNumList[46][11] = {
    "1183626989", "126905485", "183626989", "1162818524", "121840318", "192836552", "178118017", "199899680", "1138542341", "166758328", "1109189316", "182865952",
    "166338870", "102290939", "1138517266", "134397596", "162237819", "189752662", "183626989", "122029171", "1193456777", "164242624", "183626989", "126905485",
    "1183626989", "162818524", "121840318", "192836552", "178118017", "199899680", "138542341", "166758328", "109189316", "182865952", "166338870", "102290939",
    "1138517266", "134397596", "162237819", "1189752662", "183626989", "122029171", "1109189316", "182865952", "166338870", "1102290939"
};

const int birthDayList[46] = {
    12, 23, 20, 30, 30, 6, 10, 22, 24, 22, 14, 11, 19, 1, 3, 30, 6, 12, 11, 12, 20, 20, 1, 
    3, 30, 12, 23, 20, 30, 30, 6, 10, 22, 24, 22, 14, 11, 19, 7, 1, 18, 19, 21, 6, 12, 11
};

const int birthMonthList[46] = {
    9, 3, 3, 12, 10, 3, 9, 1, 9, 11, 8, 7, 4, 6, 4, 11, 1, 8, 7, 9, 10, 1, 6, 
    4, 11, 9, 3, 3, 12, 10, 3, 9, 1, 9, 11, 8, 7, 4, 3, 8, 12, 8, 1, 1, 8, 7
};

const int birthYearList[46] = {
    1985, 1989, 1987, 1993, 1996, 1977, 1983, 1989, 1990, 1972, 1979, 1977, 1976, 1980, 1980,
    1989, 1995, 1999, 1994, 1989, 1977, 1996, 1980, 1980, 1989, 1989, 1985, 1987, 1993, 1996,
    1977, 1983, 1989, 1990, 1972, 1979, 1977, 1976, 1990, 1986, 1982, 1993, 1981, 1995, 1999, 1994
};

int userDataInjection() {
    FILE *fileInitializer = fopen("user.txt", "w");

    for (int i = 0; i < DATA_SIZE; i++) {
        Account user;
        strcpy(user.email, emailList[i]);
        strcpy(user.name, nameList[i]);
        strcpy(user.username, usernameList[i]);
        strcpy(user.password, passwordList[i]);
        strcpy(user.contactNum, contactNumList[i]);
        user.dateOfBirth.day = birthDayList[i];
        user.dateOfBirth.month = birthMonthList[i];
        user.dateOfBirth.year = birthYearList[i];
        user.userType = i > 19 ? 'u' : 'a';

        fwrite(&user, sizeof(Account), 1, fileInitializer);
        if (fwrite != 0) {
            printf("%s's account (%s) has been registered successfully!\n", user.username, user.userType == 'u' ? "user" : "admin");
        } else {
            printf("Error registering %s!\n", fileInitializer);
        };
    }

    fclose(fileInitializer);

    return 0;
};
