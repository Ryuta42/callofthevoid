//window.cpp

#include "header/constants.hpp"
#include "header/window.hpp"

Window::Window()
{
    loadSuccess = true;
    
    //initialize SDL objects
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL)
    {
        cout << "Failed to create window: " << SDL_GetError() << endl;
        loadSuccess = false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        cout << "Renderer error: " << SDL_GetError() << endl;
        loadSuccess = false;
    }
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        cout << "PNG Load error: " << IMG_GetError() << endl;
        loadSuccess = false;
    }
    if (TTF_Init() == -1)
    {
        cout << "SDL_ttf error: " << TTF_GetError() << endl;
        loadSuccess = false;
    }
    
    //sprite sheets
    addTexture("assets/knight.png", SHEET_KNIGHT);
}

Window::~Window()
{
    //clean up SDL
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    for (int i = texture.size(); i > 0; i--)
    {
        SDL_DestroyTexture(texture.back());
        texture.pop_back();
    }
}

void Window::clear()
{
    //clear
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Window::draw(Frame* frame)
{
    crop = frame->getCrop();
    pos = frame->getPos();
    
    //scale to pixel ration
    pos = rect_mult(pos, PIXEL_RATIO);
    
    SDL_RenderCopy(renderer, texture.at(frame->getSheet()), &crop, &pos);
    
    //for debug: show hit/punish boxes
    if (SHOW_BOXES)
    {
        //show hit boxes
        RectList* rectlist = frame->getHitBox();
        for (int i = rectlist->getSize()-1; i >= 0; i--)
        {
            crop = rect_mult(rectlist->getRect(i), PIXEL_RATIO);
            crop.x = crop.x + frame->getX() * PIXEL_RATIO;
            crop.y = crop.y + frame->getY() * PIXEL_RATIO;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
            SDL_RenderDrawRect(renderer, &crop);
        }
    
        //show punish boxes
        rectlist = frame->getPunishBox();
        for (int i = rectlist->getSize()-1; i >= 0; i--)
        {
            crop = rect_mult(rectlist->getRect(i), PIXEL_RATIO);
            crop.x = crop.x + frame->getX() * PIXEL_RATIO;
            crop.y = crop.y + frame->getY() * PIXEL_RATIO;
            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 0);
            SDL_RenderDrawRect(renderer, &crop);
        }
        
        //show stand boxes
        rectlist = frame->getStandBox();
        for (int i = rectlist->getSize()-1; i >= 0; i--)
        {
            crop = rect_mult(rectlist->getRect(i), PIXEL_RATIO);
            crop.x = crop.x + frame->getX() * PIXEL_RATIO;
            crop.y = crop.y + frame->getY() * PIXEL_RATIO;
            SDL_SetRenderDrawColor(renderer, 50, 255, 50, 0);
            SDL_RenderDrawRect(renderer, &crop);
        }
    }
}

void Window::render()
{
    //render
    SDL_RenderPresent(renderer);
}

bool Window::getLoadSuccess() { return loadSuccess; }

void Window::addTexture(string path, int sheet_id)
{
    SDL_Texture* temp;
    texture.push_back(temp);
    texture_name.push_back(sheet_id);
    texture.back() = IMG_LoadTexture(renderer, path.c_str());
    if (texture.back() == NULL)
    {
        cout << "Image load error: " << IMG_GetError() << endl;
        loadSuccess = false;
    }
}