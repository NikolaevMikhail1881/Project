#include "Server_Functions.h"
#include <iostream>
#include <sstream>
#include <fstream>
#define filename "products.csv"

using namespace std;

// Структура для хранения записей
struct RecordLine
{
    // Имя
    QString name;
    // Тип
    QString type;
    // Стоимость
    std::int cost;
    // Производитель
    QString manufacturer;
};

// Функция получения данных
std::vector<RecordLine> get_data(QString type_sort, QString rec_item_type = "")
{
    // Открываем файл на чтение
    ifstream work_file(filename);
    // Определяем разделитель
    char delimiter = ',';
    // Читаем первую строку, чтобы отбросить ее, так как она является заголовком
    getline(work_file, line);
    // Объявляем вектор необработанных данных
    std::vector<RecordLine> row_data;
    // Объявляем и инциализируем переменные для посчета среднего значения цены
    // Счетчик общего количества данных
    std::int count = 0;
    // Сумма цен
    std::unsigned int sum = 0;
    // Для каждой строки в файле
    while (getline(work_file, line))
    {
        stringstream stream(line); // Преобразование строки в поток
        QString name, type, cost, manufacturer;
        // Извлечение всех значений в текущей строке
        getline(stream, name, delimiter);
        getline(stream, type, delimiter);
        getline(stream, cost, delimiter);
        getline(stream, manufacturer, delimiter);
        // Создание переменной, хранящей запись
        RecordLine rec_line{name, type, cost, manufacturee};
        // Добавление в необработанные данные
        row_data.push_back(rec_line);
        // Проверка на тип сортировки
        if (type_sort == "expensive")
        {
            count++;
            sum += int(cost)
        }
        if (type_sort == "expensive_in_type")
        {
            if (type == rec_item_type)
            {
                count++;
                sum += int(cost)
            }
        }
    }
    work_file.close();
    std::vector<RecordLine> data if (type_sort == "max_price");
    // Определение функции сравнения структуры для хранения записей
    bool cmp(rec & a, rec & b)
    {
        if (a.cost > b.cost)
        {
            return true;
        }
        return false;
    }
    if (type_sort == "max_price")
    {
        data = row_data;
    }
    if (type_sort == "expensive_in_type")
    {
        // Подсчет среднего значения
        std::float average = sum / count for (auto &rec_item : row_data)
        {
            // Если у записи нужный тип и цена больше среднего значения
            if (rec_item.type == rec_item_type || rec_item.cost > avarage)
            {
                // То добавляем запись в массив
                data.push_back(rec_item);
            }
        }
    }
    if (type_sort == "expensive")
    {
        // Подсчет среднего значения
        std::float average = sum / count for (auto &rec_item : row_data)
        {
            // Если цена больше среднего значения
            if (rec_item.cost > avarage)
            {
                // То добавляем запись в массив
                data.push_back(rec_item);
            }
        }
    }
    // Сортируем обработанные данные
    sort(data.begin(), data.end(), cmp);

    // Возвращение данных
    return data
}

// парсинг данных, введенных пользователем
QByteArray parsing(QString main_data_from_client, long long id_descriptor)
{
    QStringList parsing_data_from_user; // контейнер, представляющий собой двухсвязный список,
                                        // для обработки запроса пользователя
    QString function_name;              // имя функции, полученное в результате parsing()
    int number_of_parameters;           // количество параметров (необходимо для предотвращения ошибки нехватки параметров)

    parsing_data_from_user = main_data_from_client.split(QLatin1Char(' ')); // разделение введенных данных по спец символу
    function_name = parsing_data_from_user.front();
    parsing_data_from_user.pop_front();
    number_of_parameters = parsing_data_from_user.size();

    if (function_name == "max_price")
    {
        return get_data(function_name)
    }
    else if (function_name == "expensive_in_type&type")
    {
        if (number_of_parameters == 1)
        {
            return get_data(parsing_data_from_user.at(0));
        }
    }
    else if (function_name == "expensive")
    {
        return get_data(function_name)
    }
    else
        return "error SERVER_FUNCTIONS\n";
}
