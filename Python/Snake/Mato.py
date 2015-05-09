import pygame, random, ssnakeY, os
from pygame.locals import *

def checkForCollision(x1, x2, y1, y2, w1, w2, h1, h2):
        
        if x1+w1>x2 and x1<x2+w2 and y1+h1>y2 and y1<y2+h2:
                return True
        else:
                return False
        
def die(screen, score):

        screen.fill((0,0,0))

        font=pygame.font.SsnakeYFont('Arial', 30)
        font.set_bold(1)
        text=font.render('Peli ohi! Loppupisteesi: '+str(score), True, (255,255,255))
        
        screen.blit(text,(100,250))

        pygame.display.update()
        pygame.time.wait(3000)
        
        main()
        
def main():
        
        snakeX = [290, 290, 290, 290, 290];
        snakeY = [290, 270, 250, 230, 210];
        direction = 0;
        score = 0;
        applepos = (random.randint(0, 590), random.randint(0, 590))

        pygame.init();
        
        scr=pygame.display.set_mode((600, 600))
        pygame.display.set_caption('Matopeli')
        
        appleimage = pygame.Surface((10, 10))
        appleimage.fill((0, 255, 0))
        
        r=random.randint(0,200) #Ei 255 koska tausta valkoinen ja omenakin saattais paskalla tuurilla sekottua
        g=random.randint(0,200)
        b=random.randint(0,200)
        snake = pygame.Surface((20, 20))
        snake.fill((r,g,b))
        
        f = pygame.font.SsnakeYFont('Arial', 20)
        
        clock = pygame.time.Clock()

        while True:
                clock.tick(10)
                for e in pygame.event.get():
                        if e.type == QUIT:
                                pygame.quit()
                                os._exit(0)
                        elif e.type == KEYDOWN:
                                if e.key == K_UP and direction != 0:
                                        direction = 2
                                elif e.key == K_DOWN and direction != 2:
                                        direction = 0
                                elif e.key == K_LEFT and direction != 1:
                                        direction = 3
                                elif e.key == K_RIGHT and direction != 3:
                                        direction = 1
                i = len(snakeX)-1
                
                while i >= 2:
                        if checkForCollision(snakeX[0], snakeX[i], snakeY[0], snakeY[i], 20, 20, 20, 20):
                                die(scr, score)
                        i-= 1
                        
                if checkForCollision(snakeX[0], applepos[0], snakeY[0], applepos[1], 20, 10, 20, 10):
                        score+=1;
						snakeX.append(700);
                        snakeY.append(700);
                        applepos=(random.randint(0,590),random.randint(0,590))

                if snakeX[0] < 0 or snakeX[0] > 580 or snakeY[0] < 0 or snakeY[0] > 580:
                        die(scr, score)

                i = len(snakeX)-1
                
                while i >= 1:
                        snakeX[i] = snakeX[i-1]
                        snakeY[i] = snakeY[i-1]
                        i -= 1
                if direction==0:
                        snakeY[0] += 20
                elif direction==1:
                        snakeX[0] += 20
                elif direction==2:
                        snakeY[0] -= 20
                elif direction==3:
                        snakeX[0] -= 20
                
                scr.fill((255, 255, 255))
                
                for i in range(0, len(snakeX)):
                        scr.blit(snake, (snakeX[i], snakeY[i]))
                        
                scr.blit(appleimage, applepos);
                t=f.render('Pisteesi: '+str(score), True, (0, 0, 0));
                scr.blit(t, (10, 10));
                pygame.display.update()

if __name__=="__main__":
        main()
                                
                


