/** @file Level.hpp
 * @brief Заголовочный файл для класса Level, управляющего картой уровня и её элементами.
 * @author akonch
 */

#ifndef LEVEL_HORIZON /**< Проверяет, не был ли файл уже включён, чтобы избежать повторного включения. */
#define LEVEL_HORIZON /**< Определяет макрос LEVEL_HORIZON для защиты от повторного включения. */

#include <vector> /**< Подключает библиотеку vector для хранения карты уровня. */
#include <string> /**< Подключает библиотеку string для работы с именем файла карты. */

class Game; /**< Предварительное объявление класса Game для избежания циклической зависимости. */

/** @brief Перечисление TileType, определяющее типы клеток на карте.
 * @author akonch
 */
enum class TileType { EMPTY, WALL, COIN, FINISH, SPIKES }; /**< Определяет типы клеток: пустая, стена, монета, финиш, шипы. */

/** @brief Класс Level, представляющий уровень игры и его элементы.
 * @author akonch
 */
class Level { /**< Объявляет класс Level. */
public: /**< Начинает секцию публичных методов и членов класса. */
    Level(); /**< Конструктор уровня, инициализирует пустой уровень. */
    void loadFromFile(const std::string& filename, Game& game, int difficulty); /**< Загружает уровень из файла с учётом сложности. */
    TileType getTile(int x, int y) const; /**< Возвращает тип клетки на заданных координатах. */
    void setTile(int x, int y, TileType type); /**< Устанавливает тип клетки на заданных координатах. */
    int getWidth() const { return width; } /**< Возвращает ширину уровня. */
    int getHeight() const { return height; } /**< Возвращает высоту уровня. */
    float getPlayerStartX() const { return playerStartX; } /**< Возвращает начальную X-координату игрока. */
    float getPlayerStartY() const { return playerStartY; } /**< Возвращает начальную Y-координату игрока. */
    const std::vector<std::pair<float, float>>& getEnemyPositions() const { return enemyPositions; } /**< Возвращает позиции врагов на уровне. */

private: /**< Начинает секцию приватных членов класса. */
    std::vector<std::vector<TileType>> tiles; /**< Двумерный вектор, хранящий карту уровня. */
    int width, height; /**< Размеры уровня (ширина и высота). */
    float playerStartX, playerStartY; /**< Начальные координаты игрока. */
    std::vector<std::pair<float, float>> enemyPositions; /**< Вектор позиций врагов (x, y). */
}; /**< Завершает определение класса Level. */

#endif /**< Завершает защиту от повторного включения файла. */
#endif