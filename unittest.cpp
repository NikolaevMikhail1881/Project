#include "unittest.h"

void TestMyTcpServer::test_heapSort() {
    QVector<QVector<int>> testCases = {
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {100, 200, 300, 400},
        {400, 300, 200, 100},
        {5, 5, 5, 5, 5},
        {1, 1, 2, 2, 3, 3},
        {6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6},
        {1, 3, 5, 7, 9, 2, 4, 6, 8},
        {9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    for (auto& testCase : testCases) {
        QVector<QVector<int>> steps = server.heapSort(testCase, testCase.size(), testCase.size());
        QVERIFY2(!steps.empty(), "Шаги не должны быть пустыми.");

        QVector<int>& sorted = steps.last();
        for (int i = 1; i < sorted.size(); i++) {
            QVERIFY2(sorted[i - 1] <= sorted[i], "Массив должен быть отсортирован в порядке возрастания.");
        }
    }
}

QTEST_APPLESS_MAIN(TestMyTcpServer)

#include "testmytcpserver.moc"
