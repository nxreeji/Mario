/** @file Player.hpp
 * @brief Заголовочный файл для класса Player, представляющего игрока в игре.
 * @author AnastaVensk
 */

#ifndef PLAYER_H /**< Проверяет, не был ли файл уже включён, чтобы избежать повторного включения. */
#define PLAYER_H /**< Определяет макрос PLAYER_H для защиты от повторного включения. */

#include "Entity.hpp" /**< Подключает заголовочный файл Entity.hpp для наследования класса Entity. */
#include "Level.hpp" /**< Подключает заголовочный файл Level.hpp для взаимодействия с уровнем. */
#include <string> /**< Подключает библиотеку string для работы со строками (название типа игрока). */

/** @brief Класс Player, представляющий игрока, наследуется от Entity.
 * @author AnastaVensk
 */
class Player : public Entity { /**< Объявляет класс Player, наследующийся от Entity. */
private: /**< Начинает секцию приватных членов класса. */
    float x, y; /**< Координаты игрока (x, y) в пространстве уровня. */
    float velocityX, velocityY; /**< Скорость игрока по осям X и Y для движения и прыжков. */
    bool onGround; /**< Флаг, указывающий, находится ли игрок на земле. */
    bool moveLeft, moveRight; /**< Флаги для движения влево и вправо. */
    bool jumpRequested; /**< Флаг, указывающий, запрошен ли прыжок. */
    int lives; /**< Количество жизней игрока. */
    int score; /**< Текущий счёт игрока (за собранные монеты). */
    std::string type; /**< Тип игрока (строка, например, "Player"). */
    float invulnerabilityTimer; /**< Таймер неуязвимости после получения урона. */
    int difficulty; /**< Уровень сложности, влияющий на количество жизней и поведение врагов. */

public: /**< Начинает секцию публичных членов класса. */
    Player(float x, float y, const std::string& type, int difficulty); /**< Конструктор игрока с начальными координатами, типом и сложностью. */
    float getX() const override { return x; } /**< Возвращает текущую координату X игрока. */
    float getY() const override { return y; } /**< Возвращает текущую координату Y игрока. */
    void setMoveLeft(bool move) { moveLeft = move; } /**< Устанавливает флаг движения влево. */
    void setMoveRight(bool move) { moveRight = move; } /**< Устанавливает флаг движения вправо. */
    void setJump(bool jump); /**< Запрашивает прыжок, если игрок на земле. */
    void resetMovement(); /**< Сбрасывает все флаги движения (влево, вправо, прыжок). */
    void update(Level& level, float deltaTime) override; /**< Обновляет состояние игрока с учётом уровня и времени кадра. */
    void takeDamage() { if (invulnerabilityTimer <= 0) { lives--; invulnerabilityTimer = 2.0f; } } /**< Наносит урон игроку, если не активна неуязвимость. */
    int getLives() const { return lives; } /**< Возвращает текущее количество жизней игрока. */
    int getScore() const { return score; } /**< Возвращает текущий счёт игрока. */
    char getSymbol() const override { return 'M'; } /**< Возвращает символ игрока для отображения ('M'). */
    float getInvulnerabilityTimer() const { return invulnerabilityTimer; } /**< Возвращает текущий таймер неуязвимости. */
}; /**< Завершает определение класса Player. */

#endif /**< Завершает защиту от повторного включения файла. */