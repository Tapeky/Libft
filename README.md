```markdown
# 📚 Libft

**Libft** est une bibliothèque personnelle en C regroupant des fonctions utilitaires pour la manipulation de chaînes, de mémoire, de listes chaînées, et plus encore.  
Ce projet est réalisé dans le cadre du cursus de l'école **42**.

---

## 🛠 Installation

1. Clonez le dépôt :
```bash
git clone https://github.com/<votre-utilisateur>/libft.git
cd libft
```

2. Compilez la bibliothèque :
```bash
make
```
*Cela générera `libft.a` (bibliothèque statique) que vous pourrez utiliser dans vos projets.*

---

## 🚀 Utilisation

### Intégration à votre projet
- **Compilation :**  
  Ajoutez `-L. -lft` à vos flags de compilation :
  ```bash
  gcc -Wall -Wextra -Werror -I. -L. -lft votre_programme.c -o votre_programme
  ```

- **Dans vos fichiers sources :**  
  Incluez l'en-tête de la bibliothèque :
  ```c
  #include "libft.h"
  ```

---

## 📦 Fonctionnalités

### 🔄 Conversion
| Fonction       | Description                          |
|----------------|--------------------------------------|
| `ft_atoi`      | Convertit une chaîne en entier       |
| `ft_itoa`      | Convertit un entier en chaîne        |
| `ft_tolower`   | Convertit un caractère en minuscule  |
| `ft_toupper`   | Convertit un caractère en majuscule  |

### 🔍 Vérifications (Is)
| Fonction       | Description                          |
|----------------|--------------------------------------|
| `ft_isalpha`   | Vérifie si un caractère est alphabétique |
| `ft_isdigit`   | Vérifie si un caractère est un chiffre |
| `ft_isalnum`   | Vérifie si un caractère est alphanumérique |
| ... *(voir libft.h)* | |

### 🧠 Mémoire
| Fonction       | Description                          |
|----------------|--------------------------------------|
| `ft_memset`    | Remplit une zone mémoire avec un octet |
| `ft_bzero`     | Met des octets à zéro                |
| `ft_calloc`    | Alloue et initialise de la mémoire   |
| ... *(14 fonctions)* | |

*(Consultez `libft.h` pour la liste complète des fonctions)*

---

## 💡 Exemple

```c
#include "libft.h"
#include <stdio.h>

// Fonction pour mettre en majuscule (compatible avec ft_striteri)
static void to_upper(unsigned int i, char *c) {
    (void)i; // Paramètre non utilisé
    *c = ft_toupper(*c);
}

int main(void) {
    char *str = ft_strdup("Libft est géniale !");
    
    printf("Longueur : %zu\n", ft_strlen(str)); // 18
    ft_striteri(str, to_upper);
    printf("MAJUSCULES : %s\n", str); // "LIBFT EST GÉNIALE !"
    
    free(str);
    return 0;
}
```

**Compilation :**
```bash
gcc -Wall -Wextra -Werror -I. -L. -lft exemple.c -o exemple && ./exemple
```

---

## 📜 Licence  
Ce projet suit les directives de l'école 42. Consultez le fichier `LICENSE` pour plus de détails.

---

## 👨💻 Auteur  
**tsadouk**  
[✉️ tsadouk@student.42.fr](mailto:tsadouk@student.42.fr)  
Étudiant à **42** | Angouleme, France
