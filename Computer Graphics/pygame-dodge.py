import pygame
import random
import math

# Initialize Pygame
pygame.init()

# Set up display
WIDTH = 800
HEIGHT = 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Cyberpunk Adventure")

# Colors
DARK_GRAY = (20, 20, 20)
NEON_BLUE = (0, 255, 255)
NEON_PINK = (255, 0, 255)
NEON_GREEN = (0, 255, 0)
NEON_RED = (255, 50, 50)

class Player:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.radius = 20
        self.speed = 5
        self.health = 100
        self.rect = pygame.Rect(x - self.radius, y - self.radius, self.radius * 2, self.radius * 2)
        
    def move(self, dx, dy):
        new_x = self.x + dx * self.speed
        new_y = self.y + dy * self.speed
        
        # Keep player on screen
        self.x = max(self.radius, min(new_x, WIDTH - self.radius))
        self.y = max(self.radius, min(new_y, HEIGHT - self.radius))
        self.rect.center = (self.x, self.y)

    def draw(self, surface):
        # Outer glow
        for i in range(5):
            alpha = 255 - i * 50
            pygame.draw.circle(surface, (*NEON_BLUE[:3], alpha), (int(self.x), int(self.y)), self.radius + i * 2, 1)
        # Main circle
        pygame.draw.circle(surface, NEON_BLUE, (int(self.x), int(self.y)), self.radius)
        # Inner glow
        for i in range(3):
            pygame.draw.circle(surface, (255, 255, 255), (int(self.x), int(self.y)), self.radius - i * 4, 1)

class Enemy:
    def __init__(self):
        self.x = random.randint(0, WIDTH)
        self.y = -30
        self.speed = random.randint(2, 4)
        self.size = 30
        self.angle = 0
        self.rotation_speed = random.uniform(-5, 5)
        self.rect = pygame.Rect(self.x - self.size // 2, self.y - self.size // 2, self.size, self.size)
    
    def move(self):
        self.y += self.speed
        self.angle += self.rotation_speed
        self.rect.center = (self.x, self.y)
    
    def is_off_screen(self):
        return self.y > HEIGHT + self.size

    def draw(self, surface):
        points = [
            (0, -self.size // 2),
            (-self.size // 2, self.size // 2),
            (self.size // 2, self.size // 2)
        ]
        rotated_points = [self.rotate_point(p, self.angle) for p in points]
        translated_points = [(p[0] + self.x, p[1] + self.y) for p in rotated_points]
        
        # Outer glow
        for i in range(5):
            alpha = 255 - i * 50
            pygame.draw.polygon(surface, (*NEON_PINK[:3], alpha), translated_points, 1)
        # Main triangle
        pygame.draw.polygon(surface, NEON_PINK, translated_points)
        # Inner glow
        for i in range(3):
            inner_points = [self.rotate_point((p[0] * (0.9 - i * 0.2), p[1] * (0.9 - i * 0.2)), self.angle) for p in points]
            inner_translated = [(p[0] + self.x, p[1] + self.y) for p in inner_points]
            pygame.draw.polygon(surface, (255, 255, 255), inner_translated, 1)

    @staticmethod
    def rotate_point(point, angle):
        x, y = point
        rad = math.radians(angle)
        cos_a, sin_a = math.cos(rad), math.sin(rad)
        return (x * cos_a - y * sin_a, x * sin_a + y * cos_a)

class Game:
    def __init__(self):
        self.player = Player(WIDTH // 2, HEIGHT - 100)
        self.enemies = []
        self.score = 0
        self.game_over = False
        self.font = pygame.font.Font(None, 36)
        self.enemy_spawn_timer = 0
        
    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r and self.game_over:
                self.__init__()  # Reset game
        return True
    
    def update(self):
        if self.game_over:
            return
        
        # Player movement
        keys = pygame.key.get_pressed()
        dx = keys[pygame.K_RIGHT] - keys[pygame.K_LEFT]
        dy = keys[pygame.K_DOWN] - keys[pygame.K_UP]
        self.player.move(dx, dy)
        
        # Spawn enemies
        self.enemy_spawn_timer += 1
        if self.enemy_spawn_timer > 60:  # Spawn enemy every second
            self.enemies.append(Enemy())
            self.enemy_spawn_timer = 0
        
        # Update enemies
        for enemy in self.enemies[:]:
            enemy.move()
            if enemy.is_off_screen():
                self.enemies.remove(enemy)
                self.score += 1
            elif self.player.rect.colliderect(enemy.rect):
                self.game_over = True
    
    def draw(self):
        # Draw background
        screen.fill(DARK_GRAY)
        self.draw_grid()
        
        # Draw player
        self.player.draw(screen)
        
        # Draw enemies
        for enemy in self.enemies:
            enemy.draw(screen)
        
        # Draw score
        score_text = self.font.render(f"Score: {self.score}", True, NEON_GREEN)
        screen.blit(score_text, (10, 10))
        
        # Draw game over
        if self.game_over:
            game_over_text = self.font.render("Game Over! Press R to restart", True, NEON_RED)
            game_over_rect = game_over_text.get_rect(center=(WIDTH/2, HEIGHT/2))
            screen.blit(game_over_text, game_over_rect)

    def draw_grid(self):
        cell_size = 40
        current_time = pygame.time.get_ticks() * 0.001
        for x in range(0, WIDTH, cell_size):
            alpha = int(127 + 128 * math.sin(current_time + x * 0.01))
            color = (*NEON_BLUE[:3], alpha)
            pygame.draw.line(screen, color, (x, 0), (x, HEIGHT))
        for y in range(0, HEIGHT, cell_size):
            alpha = int(127 + 128 * math.sin(current_time + y * 0.01))
            color = (*NEON_BLUE[:3], alpha)
            pygame.draw.line(screen, color, (0, y), (WIDTH, y))

def main():
    clock = pygame.time.Clock()
    game = Game()
    running = True
    
    try:
        while running:
            running = game.handle_events()
            game.update()
            game.draw()
            pygame.display.flip()
            clock.tick(60)
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        pygame.quit()

if __name__ == "__main__":
    main()