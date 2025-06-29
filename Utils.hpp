/** @file Utils.hpp
 * @brief Заголовочный файл для вспомогательных функций, таких как логирование.
 * @author KolobovaAlexsandra
 */

#ifndef UTILS_HORIZON /**< Проверяет, не был ли файл уже включён, чтобы избежать повторного включения. */
#define UTILS_HORIZON /**< Определяет макрос UTILS_HORIZON для защиты от повторного включения. */

#include <string> /**< Подключает библиотеку string для работы с текстом времени. */
#include <fstream> /**< Подключает библиотеку для работы с файлами (логирование). */

/** @brief Возвращает текущее время в формате строки для логирования.
 * @return Строка с текущим временем в формате [YYYY-MM-DD HH:MM:SS].
 * @author KolobovaAlexsandra
 */
std::string getCurrentTime(); /**< Объявляет функцию получения текущего времени. */

/** @brief Глобальная переменная debugLog для записи логов в файл debug.log.
 * @author KolobovaAlexsandra
 */
extern std::ofstream debugLog; /**< Объявляет внешнюю переменную для логирования. */

#endif /**< Завершает защиту от повторного включения файла. */
#endif
