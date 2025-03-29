FONTS = $(wildcard fonts/*.ttf)
FONT_HEADERS = $(patsubst fonts/%.ttf, src/fonts/%.h, $(FONTS))

.PHONY: fonts
fonts: $(FONT_HEADERS)

src/fonts/%.h: fonts/%.ttf
	fontconvert $^ 12 > src/fonts/$(subst -,_,$*)12pt7b.h
	fontconvert $^ 14 > src/fonts/$(subst -,_,$*)14pt7b.h
	fontconvert $^ 15 > src/fonts/$(subst -,_,$*)15pt7b.h
	fontconvert $^ 16 > src/fonts/$(subst -,_,$*)16pt7b.h
	fontconvert $^ 18 > src/fonts/$(subst -,_,$*)18pt7b.h
	fontconvert $^ 24 > src/fonts/$(subst -,_,$*)24pt7b.h
	fontconvert $^ 48 > src/fonts/$(subst -,_,$*)48pt7b.h
	fontconvert $^ 60 > src/fonts/$(subst -,_,$*)60pt7b.h
	fontconvert $^ 92 > src/fonts/$(subst -,_,$*)92pt7b.h