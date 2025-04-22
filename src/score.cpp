#include <header.hpp>

bool Apple_eaten(Snake *snake, Apple &apple) {
	if(snake->s_pos[0].x == apple.x && snake->s_pos[0].y == apple.y) {
		apple.visible = false;
		return true;
	}
	return false;
}

void updateScore(Player &player, Snake *snake, Apple &apple) {
	//permanentIncrease
	player.score += 2;

	if(Apple_eaten(snake, apple))	player.score += 50;

	if(player.score > snake->new_tail) {
		snake->addTail();
		snake->new_tail += 400;
	}	
}
