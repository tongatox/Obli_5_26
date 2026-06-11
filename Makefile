# =============================================================================
# Makefile dinámico — Obli_5_26
# =============================================================================
# ¿Qué hace?
#   1. Busca automáticamente todos los .cpp del proyecto (no hay que listarlos a mano).
#   2. Compila cada uno a un .o dentro de build/, conservando la estructura de carpetas.
#   3. Enlaza todos los .o y genera el ejecutable en bin/.
#   4. Regenera dependencias de headers (.d) para recompilar solo lo que cambió.
#
# Uso habitual:
#   make          → compila el proyecto
#   make run      → compila y ejecuta
#   make clean    → borra artefactos de compilación
#   make rebuild  → limpia y vuelve a compilar todo
# =============================================================================

# -----------------------------------------------------------------------------
# Herramientas y flags del compilador
# -----------------------------------------------------------------------------
# Compilador C++
CXX := g++
# Estándar C++11, warnings activos y símbolos de debug (-g)
CXXFLAGS := -std=c++11 -Wall -Wextra -g
# Genera archivos .d con dependencias de headers para recompilar solo lo necesario
CXXFLAGS += -MMD -MP

# -----------------------------------------------------------------------------
# Rutas de salida
# -----------------------------------------------------------------------------
# Ejecutable final
TARGET := bin/obli
# Carpeta donde se guardan objetos (.o) y dependencias (.d)
BUILD_DIR := build

# -----------------------------------------------------------------------------
# Descubrimiento automático de fuentes
# -----------------------------------------------------------------------------
# find recorre el árbol desde la raíz, excluyendo carpetas de build y git.
# sed quita el "./" inicial para que las reglas de Make matcheen bien.
SOURCES := $(shell find . -name '*.cpp' \
	-not -path './$(BUILD_DIR)/*' \
	-not -path './bin/*' \
	-not -path './.git/*' \
	| sed 's|^\./||' \
	| sort)

# Cada .cpp → un .o en build/ con la misma ruta relativa.
# Ejemplo: collections/UsuarioCollection.cpp → build/collections/UsuarioCollection.o
OBJECTS := $(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))

# Archivos de dependencias generados por -MMD (un .d por cada .o)
DEPS := $(OBJECTS:.o=.d)

# -----------------------------------------------------------------------------
# Includes dinámicos
# -----------------------------------------------------------------------------
# Todas las carpetas del proyecto se agregan con -I, así los #include "../entities/..."
# y los #include "Usuario.h" resuelven sin configurar rutas a mano.
INCLUDE_DIRS := $(shell find . -type d \
	\( -path ./$(BUILD_DIR) -o -path ./bin -o -path ./.git \) -prune \
	-o -type d -print \
	| sed 's|^\./||' \
	| sort)
INCLUDES := $(addprefix -I,$(INCLUDE_DIRS))

# -----------------------------------------------------------------------------
# Regla por defecto
# -----------------------------------------------------------------------------
.PHONY: all
all: $(TARGET)

# -----------------------------------------------------------------------------
# Enlazado: junta todos los .o en el ejecutable
# -----------------------------------------------------------------------------
$(TARGET): $(OBJECTS) | bin
	@echo "==> Enlazando $@"
	$(CXX) $(OBJECTS) -o $@

# Crea la carpeta bin/ si no existe (prerrequisito de orden, no se recompila por cambios ahí)
bin:
	@mkdir -p bin

# -----------------------------------------------------------------------------
# Compilación: cada .cpp → su .o en build/
# -----------------------------------------------------------------------------
# La regla con patrón funciona para cualquier subcarpeta gracias a mkdir -p.
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "==> Compilando $<"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------------
# Incluir dependencias de headers (recompilación incremental)
# -----------------------------------------------------------------------------
# El "-" hace que no falle si los .d aún no existen en la primera compilación.
-include $(DEPS)

# -----------------------------------------------------------------------------
# Objetivos auxiliares
# -----------------------------------------------------------------------------
.PHONY: run
run: $(TARGET)
	@echo "==> Ejecutando $(TARGET)"
	./$(TARGET)

.PHONY: clean
clean:
	@echo "==> Limpiando $(BUILD_DIR)/ y bin/"
	rm -rf $(BUILD_DIR) bin

.PHONY: rebuild
rebuild: clean all

.PHONY: info
info:
	@echo "Ejecutable : $(TARGET)"
	@echo "Fuentes    : $(words $(SOURCES)) archivos .cpp"
	@echo "Objetos    : $(words $(OBJECTS)) archivos .o"
	@echo "Includes   : $(INCLUDE_DIRS)"

.PHONY: help
help:
	@echo "Objetivos disponibles:"
	@echo "  make         Compila el proyecto (por defecto)"
	@echo "  make run     Compila y ejecuta bin/obli"
	@echo "  make clean   Elimina build/ y bin/"
	@echo "  make rebuild Limpia y recompila desde cero"
	@echo "  make info    Muestra fuentes, objetos e includes detectados"
	@echo "  make help    Muestra esta ayuda"
