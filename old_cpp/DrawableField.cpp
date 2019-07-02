/*
 * DrawableField.cpp
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/DrawableField.h>

DrawableField::DrawableField() {
	this->init();
}

DrawableField::~DrawableField() {
	// TODO Auto-generated destructor stub
}

void DrawableField::draw_line(Point3D *p1, Point3D *p2){
	BSP_LCD_DrawLine(p1->x + get_draw_pos_x(),
					p1->y + get_draw_pos_y(),
					p2->x + get_draw_pos_x(),
					p2->y + get_draw_pos_y());
}

void DrawableField::init(){
	this->__draw_background();
	this->set_back_color(0,0,0);
	this->__draw_title();
}

// need optimize
void DrawableField::draw_polygon(Polygon *p_vec){
	Point *p = new Point[p_vec->p_cnt];
	for (uint8_t i = 0; i < p_vec->p_cnt; ++i) {
		p[i].X = p_vec->points[i]->x;
		p[i].Y = p_vec->points[i]->y;
	}
	BSP_LCD_FillPolygon(p, (uint16_t)p_vec->size());
}

void DrawableField::set_color(uint8_t r, uint8_t g, uint8_t b){
	this->r = r;
	this->g = g;
	this->b = b;
	BSP_LCD_SetTextColor(this->get_color());
}

void DrawableField::set_back_color(uint8_t r_b, uint8_t g_b, uint8_t b_b){
	this->r_b = r_b;
	this->g_b = g_b;
	this->b_b = b_b;
	BSP_LCD_SetBackColor(this->get_back_color());
}

uint32_t DrawableField::get_color(){
	return (r << 11) | (g << 5) | (b);
}

uint32_t DrawableField::get_back_color(){
	return (r_b << 11) | (g_b << 5) | (b_b);
}

void DrawableField::draw_point(Point3D *p){
	BSP_LCD_DrawPixel(	p->x + get_draw_pos_x(),
						p->y + get_draw_pos_y(),
						this->get_color());
}

void DrawableField::clear_background(){
	this->__draw_background();
}

void DrawableField::__draw_background(){
	this->set_color(0,0,0);
	BSP_LCD_FillRect(get_win_pos_x(), get_win_pos_y(), get_win_width(), get_win_height());
	this->set_color(0x1f,0x1f,0x1f);
}

void DrawableField::__draw_title(){
	BSP_LCD_DisplayStringAt(get_win_pos_x(),
							get_win_pos_y(),
							(unsigned char *)get_title().data(),
							Text_AlignModeTypdef::LEFT_MODE);
}
