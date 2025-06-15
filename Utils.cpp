/** @file Utils.cpp
 * @brief Реализация вспомогательных функций, таких как получение текущего времени для логирования.
 * @author KolobovaAlexsandra
 */

#include "Utils.hpp" /**< Подключает заголовочный файл Utils.hpp с объявлениями функций. */
#include <ctime> /**< Подключает библиотеку для работы с временем. */
#include <iomanip> /**< Подключает библиотеку для форматирования вывода времени. */

/** @brief Глобальная переменная debugLog для записи логов в файл debug.log.
 * @author KolobovaAlexsandra
 */
std::ofstream debugLog("debug.log", std::ios::app); /**< Инициализирует файл логов в режиме добавления. */

/** @brief Возвращает текущее время в формате строки для логирования.
 * @return Строка с текущим временем в формате [YYYY-MM-DD HH:MM:SS].
 * @author KolobovaAlexsandra
 */
std::string getCurrentTime() { /**< Объявляет функцию получения текущего времени. */
    auto now = std::time(nullptr); /**< Получает текущее время в секундах с эпохи. */
    std::stringstream ss; /**< Создаёт строковый поток для форматирования времени. */
    ss << std::put_time(std::localtime(&now), "[%Y-%m-%d %H:%M:%S]"); /**< Форматирует время в строку [YYYY-MM-DD HH:MM:SS]. */
    return ss.str(); /**< Возвращает отформатированную строку времени. */
} /**< Завершает функцию getCurrentTime. */
