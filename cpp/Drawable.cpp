/*
 * Drawable.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <Drawable.h>

Drawable::Drawable() {
	// TODO Auto-generated constructor stub
	color.set_color(0x1F, 0, 0);
	text_back_color.set_color(COLOR_MAX_R, COLOR_MAX_G, COLOR_MAX_B);
	set_draw_color(color);
	set_text_back_color(text_back_color);
	init_font();
	swap_buffers();
	set_draw_color(color);
	set_text_back_color(text_back_color);
	init_font();
	/*BSP_LCD_SelectLayer(1);
	clear_display();
	BSP_LCD_SelectLayer(0);
	clear_display();
	swap_buffers();*/
}

Drawable::~Drawable() {
	// TODO Auto-generated destructor stub
}


void Drawable::draw_line(Point2d p1, Point2d p2){
	BSP_LCD_DrawLine(p1.x, p1.y, p2.x, p2.y);
}

void Drawable::draw_point(Point2d p){
	BSP_LCD_DrawPixel(p.x, p.y, color.get_color());
}

void Drawable::draw_rect(Point2d p1, x16 width, x16 height){
	BSP_LCD_DrawRect(p1.x, p1.y, width, height);
}

void Drawable::draw_rect(x16 x, x16 y, x16 width, x16 height){
	BSP_LCD_DrawRect(x, y, width, height);
}

void Drawable::draw_fill_rect(Point2d p1, x16 width, x16 height){
	BSP_LCD_FillRect(p1.x, p1.y, width, height);
}

void Drawable::draw_fill_rect(x16 x, x16 y, x16 width, x16 height){
	BSP_LCD_FillRect(x, y, width, height);
}

void Drawable::draw_polygon(Polygon *p){
	BSP_LCD_DrawPolygon(convert_to_point(p), p->p_cnt);
}

void Drawable::draw_fill_polygon(Polygon *p){
	BSP_LCD_FillPolygon(convert_to_point(p), p->p_cnt);
}


////////////////////////////////////////////////TEST////////////////////////
Point *convert_to_point(Polygon *p){
	Point points[p->p_cnt];
	for (uint8_t i = 0; i < p->p_cnt; ++i) {
		points[i].X = p->points[i].x;
		points[i].Y = p->points[i].y;
	}
	return points;
}

void Drawable::draw_text(unsigned char *text, Point2d pos){
	BSP_LCD_DisplayStringAt(pos.x, pos.y, text, Text_AlignModeTypdef::LEFT_MODE);
}

void Drawable::clear_display(){
	BSP_LCD_Clear(background_color.get_color());
}

void Drawable::set_draw_color(Color c){
	color = c;
	BSP_LCD_SetTextColor(color.get_color());
}

void Drawable::set_text_back_color(Color c){
	text_back_color = c;
	BSP_LCD_SetBackColor(text_back_color.get_color());
}

Color *Drawable::get_draw_color(){
	return &color;
}

Color *Drawable::get_text_back_color(){
	return &text_back_color;
}

void Drawable::swap_buffers(){
	set_active_layer(active_layer);
	active_layer ^= 1;
	BSP_LCD_SelectLayer(active_layer);
	clear_display();
}

void Drawable::set_active_layer(x8 layer){
	if (layer == 1){
		LTDC_Layer1->CFBAR = BUFFER1_ADDR;
		LTDC->SRCR = LTDC_SRCR_VBR;                     // reload shadow registers on vertical blank
		while ((LTDC->CDSR & LTDC_CDSR_VSYNCS) == 0){}
	} else {
		LTDC_Layer1->CFBAR = BUFFER0_ADDR;
		LTDC->SRCR = LTDC_SRCR_VBR;                     // reload shadow registers on vertical blank
		while ((LTDC->CDSR & LTDC_CDSR_VSYNCS) == 0){}
	}
}

x8 Drawable::get_active_layer(){
	return active_layer;
}

void Drawable::init_font(){
	BSP_LCD_SetFont(&font);
}




















