/** @file Enemy.hpp
 * @brief Заголовочный файл для класса Enemy, представляющего врага в игре.
 * @author AnastaVensk
 */

#ifndef ENEMY_HORIZON /**< Проверяет, не был ли файл уже включён, чтобы избежать повторного включения. */
#define ENEMY_HORIZON /**< Определяет макрос ENEMY_HORIZON для защиты от повторного включения. */

#include "Level.hpp" /**< Подключает заголовочный файл Level.hpp для взаимодействия с уровнем. */
#include "Entity.hpp" /**< Подключает заголовочный файл Entity.hpp для наследования класса Entity. */

/** @brief Класс Enemy, представляющий врага, наследуется от Entity.
 * @author AnastaVensk
 */
class Enemy : public Entity { /**< Объявляет класс Enemy, наследующийся от Entity. */
public: /**< Начинает секцию публичных методов и членов класса. */
    Enemy(float x, float y, int difficulty); /**< Конструктор врага с начальными координатами и сложностью. */
    void update(Level& level, float deltaTime) override; /**< Обновляет состояние врага с учётом уровня и времени кадра. */
    float getX() const override { return x; } /**< Возвращает текущую координату X врага. */
    float getY() const override { return y; } /**< Возвращает текущую координату Y врага. */
    char getSymbol() const override { return 'E'; } /**< Возвращает символ врага для отображения ('E'). */

private: /**< Начинает секцию приватных членов класса. */
    float x, y; /**< Координаты врага (x, y) в пространстве уровня. */
    float velocityX; /**< Горизонтальная скорость врага для движения. */
}; /**< Завершает определение класса Enemy. */

#endif /**< Завершает защиту от повторного включения файла. */
#endif