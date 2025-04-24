#include "PathFinder.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
//this is a helper function that checks if coord is on the border of the maze
static inline bool isOnBorder(const Coord &p, const Image<Pixel> &img) {
    return (p.row == 0 || p.row == img.height()-1 ||
            p.col == 0 || p.col == img.width()-1);
}

PathFinder::PathFinder(const Image<Pixel> &img)
{
    load(img);
} // Constructor delegates to load() function

void PathFinder::load(const Image<Pixel> &img)
{
    checkImage(img);
    image = img;
    deadEndCount = 0;//checkoff reset deadend count
}

PathFinder::~PathFinder()
{
    clear();
} // Destructor delegates to clear() function
//checkimage first ensures the input image is a valid maze
//it must contain 1 red pixel exactly, and only white black or red pixels otherwise throws invalid args
//goes over every pixel to ensure only one red pixel exists otherwise invalid arg
void PathFinder::checkImage(const Image<Pixel> &img)
{
    int redCount = 0;
    for (int r = 0; r < img.height(); ++r) {
        for (int c = 0; c < img.width(); ++c) {
            Pixel p = img(r, c);
            if (!(p == WHITE || p == BLACK || p == RED)) {
                throw std::invalid_argument("Image has invalid pixel color.");
            }
            if (p == RED) {
                redCount++;
            }
        }
    }
    if (redCount != 1) {
        throw std::invalid_argument("Image must have exactly one red pixel.");
    }
}

//gets the start coord
//it uses visited[][] to ensure you only visit a cell once
//parent[][] is for constructing the path
void PathFinder::findPath(std::string strategy) {
    deadEndCount = 0;
    Coord start = getStart();
    
    if (isOnBorder(start, image)) {
        image(start.row, start.col) = GREEN;
        end = start;
        deadEndCount = 0;
        return;
    }
    std::vector<std::vector<bool>> visited(image.height(), std::vector<bool>(image.width(), false));
    std::vector<std::vector<Coord>> parent(image.height(), std::vector<Coord>(image.width(), Coord(-1, -1)));
    visited[start.row][start.col] = true;
    
    Queue<Coord, List<Coord>> frontier;
    frontier.enqueue(start);
    
    bool exitFound = false;
    Coord exitCoord;
    //this loop ends when an exit is found or forntier is empty
    while (!frontier.isEmpty() && !exitFound) {
        Coord cur = frontier.peekFront();
        frontier.dequeue();
        bool moved = false;
        for (char dir : strategy) {
            Coord next = cur;
            switch (dir) {
                case 'N': next.row = cur.row - 1; break;
                case 'S': next.row = cur.row + 1; break;
                case 'W': next.col = cur.col - 1; break;
                case 'E': next.col = cur.col + 1; break;
                default: continue;
            }
            if (next.row < 0 || next.row >= image.height() || 
                next.col < 0 || next.col >= image.width())
                continue;
            if (visited[next.row][next.col] || image(next.row, next.col) != WHITE)
                continue;
            
            //marks the coords then checks for exit
            moved = true;
            visited[next.row][next.col] = true;
            parent[next.row][next.col] = cur;
            frontier.enqueue(next);
            if (isOnBorder(next, image)) {
                exitCoord = next;
                exitFound = true;
                break;
            }
        }
        if (!moved){
            ++deadEndCount;
    }
    }
    
    if (!exitFound) {
        throw std::runtime_error("No path found.");
    }
    
    image(exitCoord.row, exitCoord.col) = GREEN;
    end = exitCoord;
    Coord cur = exitCoord;
    while (cur != start) {
        if (cur != start && cur != exitCoord) {
            image(cur.row, cur.col) = YELLOW;
        }
        cur = parent[cur.row][cur.col];
    }
}

void PathFinder::findPathWithVisualization(const std::string &outfile, int frame_duration, int frame_gap, std::string strategy)
{
    // frame_duration and frame_gap should stay the same throughout the function

    // Initialize GIF writer
    int cell_size = 1; // Each cell is 1x1 pixels, you can change this to a larger size if needed
    int gif_height = image.height() * cell_size;
    int gif_width = image.width() * cell_size;

    int frame_counter = 0; // each movement is a frame and you can define how frequently you want to write the frame

    GifWriter gif; // a gif object has been declared and is pending for writing
    if (!GifBegin(&gif, (outfile + ".gif").c_str(), gif_width, gif_height, frame_duration, 8, true))
    {
        throw std::runtime_error("Failed to create GIF file.");
    }
    Coord start = getStart();
    if (isOnBorder(start, image))
    {
        image(start.row, start.col) = GREEN;
        addFrameToGif(gif, frame_duration);
        writeSolutionToFile(outfile + "_final_visual.png");
        GifEnd(&gif);
        end = start;
        return;
    }
    int height = image.height();
    int width = image.width();
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::vector<std::vector<Coord>> parent(height, std::vector<Coord>(width, Coord(-1, -1)));
    visited[start.row][start.col] = true;
    Queue<Coord, List<Coord>> frontier;
    frontier.enqueue(start);
    bool exitFound = false;
    Coord exitCoord;
    while (!frontier.isEmpty() && !exitFound)
    {
        Coord cur = frontier.peekFront();
        frontier.dequeue();
        for (char dir : strategy)
        {
            Coord next = cur;
            switch (dir)
            {
            case 'N': next.row = cur.row - 1; break;
            case 'S': next.row = cur.row + 1; break;
            case 'W': next.col = cur.col - 1; break;
            case 'E': next.col = cur.col + 1; break;
            default: continue;
            }
            if (next.row < 0 || next.row >= height || next.col < 0 || next.col >= width)
                continue;
            if (visited[next.row][next.col] || image(next.row, next.col) != WHITE)
                continue;
            //colors new found cells blue, then adds a frame
            visited[next.row][next.col] = true;
            parent[next.row][next.col] = cur;
            image(next.row, next.col) = BLUE;
            frontier.enqueue(next);
            frame_counter++;
            if (frame_counter % frame_gap == 0)
            {
                addFrameToGif(gif, frame_duration);
            }
            if (isOnBorder(next, image))
            {
                exitCoord = next;
                exitFound = true;
                break;
            }
        }
    }
    if (!exitFound)
    {
        GifEnd(&gif);
        throw std::runtime_error("No path found.");
    }
    image(exitCoord.row, exitCoord.col) = GREEN;
    end = exitCoord;
    Coord cur = exitCoord;
    while (cur != start)
    {
        if (cur != start && cur != exitCoord)
        {
            image(cur.row, cur.col) = YELLOW;
        }
        cur = parent[cur.row][cur.col];
    }
    addFrameToGif(gif, frame_duration);
    writeSolutionToFile(outfile + "_final_visual.png");
    GifEnd(&gif);
}

// Helper function
void PathFinder::addFrameToGif(GifWriter &gif, int frame_duration)
{
    // Each coordinate is 1x1 pixels, you can change this to a larger size if needed
    int cell_size = 1;
    int gif_height = image.height() * cell_size;
    int gif_width = image.width() * cell_size;
    // 4 is the number of channels (RGBA)
    std::vector<uint8_t> rgb_data(gif_height * gif_width * 4);

    // Convert the image to RGB format for the GIF
    for (int r = 0; r < image.height(); ++r)
    {
        for (int c = 0; c < image.width(); ++c)
        {
            Pixel color;
            if (image(r, c) == WHITE)
            {
                color = {255, 255, 255};
            }
            else if (image(r, c) == BLACK)
            {
                color = {0, 0, 0};
            }
            else if (image(r, c) == RED)
            {
                color = {255, 0, 0};
            }
            else if (image(r, c) == GREEN)
            {
                color = {0, 255, 0};
            }
            else if (image(r, c) == BLUE)
            {
                color = {0, 0, 255};
            }
            else if (image(r, c) == YELLOW)
            {
                color = {255, 255, 0};
            }
            else
            {
                color = {0, 0, 0};
            }

            // Fill the cell with the color
            for (int i = 0; i < cell_size; ++i)
            {
                for (int j = 0; j < cell_size; ++j)
                {
                    int pixel_row = r * cell_size + i;
                    int pixel_col = c * cell_size + j;
                    int index = (pixel_row * gif_width + pixel_col) * 4;
                    rgb_data[index + 0] = color.red;
                    rgb_data[index + 1] = color.green;
                    rgb_data[index + 2] = color.blue;
                    rgb_data[index + 3] = 255; // Alpha channel
                }
            }
        }
    }
    // Write the frame to the GIF
    GifWriteFrame(&gif, rgb_data.data(), gif_width, gif_height, frame_duration, 8, true);
} // Finished

void PathFinder::writeSolutionToFile(const std::string &filename)
{
    writeToFile(image, filename);
} // delegate to writeToFile function in lib/image.h

Coord PathFinder::getStart()
{
    for (int r = 0; r < image.height(); ++r) {
        for (int c = 0; c < image.width(); ++c) {
            if (image(r, c) == RED) {
                return Coord(r, c);
            }
        }
    }
    return Coord();
}

Coord PathFinder::getEnd()
{
return end;
}

void PathFinder::clear()
{
    image = Image<Pixel>();
    end = Coord();
    deadEndCount = 0; //checkoff q set deadend to 0
}

// Nonmember functions
bool compareImagesExit(std::string img1_str, std::string img2_str)
{
    Image<Pixel> img1 = readFromFile(img1_str);
    Image<Pixel> img2 = readFromFile(img2_str);
    if (img1.width() != img2.width() || img1.height() != img2.height())
    {
        return false;
    }
    for (int r = 0; r < img1.height(); ++r)
    {
        for (int c = 0; c < img1.width(); ++c)
        {
            // Check if the pixels are different and one of them is GREEN
            if (img1(r, c) != img2(r, c) && (img1(r, c) == GREEN || img2(r, c) == GREEN))
            {
                return false;
            }
        }
    }
    return true;
} // Finished

bool compareImages(std::string img1_str, std::string img2_str)
{
    Image<Pixel> img1 = readFromFile(img1_str);
    Image<Pixel> img2 = readFromFile(img2_str);
    if (img1.width() != img2.width() || img1.height() != img2.height())
    {
        return false;
    }
    for (int r = 0; r < img1.height(); ++r)
    {
        for (int c = 0; c < img1.width(); ++c)
        {
            if (img1(r, c) != img2(r, c))
            {
                return false;
            }
        }
    }
    return true;
} // Finished

int PathFinder::getDeadEndCount() const {
    return deadEndCount;
}