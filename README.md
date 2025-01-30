# 🤖 IA Vision - Robotique avec Huskylens et Arduino Mega

**IA Vision** est un projet de robotique embarquée utilisant un **Arduino Mega** et une **caméra Huskylens** pour la détection et la reconnaissance d’objets. Ce projet fait partie du **TP SYS4041 - Robotique** et vise à doter un robot de capacités autonomes pour suivre des objets et interagir avec son environnement.

## 🎯 Objectifs du Projet
- Utiliser la caméra **Huskylens** pour l’apprentissage et la reconnaissance d’objets et de couleurs.
- Programmer un **robot mobile** capable de détecter un tag et de suivre sa cible.
- Implémenter un **mode chasseur de balles**, où le robot identifie et interagit avec des objets placés dans son environnement.
- Exploiter les capacités de l’**Arduino Mega (ATMega 2560)** pour le contrôle du robot et des moteurs.

## 🛠️ Technologies et Matériel Utilisé
- **Arduino Mega 2560** – Microcontrôleur principal du robot.
- **Huskylens** – Caméra intelligente pour la reconnaissance d’objets et de couleurs.
- **Moteurs à encodeurs** – Contrôle de la mobilité du robot.
- **Capteurs** – Détection et interaction avec l’environnement.
- **Langage : C++** – Programmation des algorithmes d’IA embarquée.

## 📌 Fonctionnalités Principales
### 🏷️ Mode "Follow-me"
Le robot est capable de :
- Détecter un tag spécifique avec la caméra Huskylens.
- S’orienter et suivre sa cible.
- Maintenir sa position par rapport à l’objet détecté.

### 🎯 Mode "Chasseur de Balles"
- Identification et classement de balles de couleurs différentes.
- Déplacement autonome pour atteindre et interagir avec les objets.
- Exécution des tâches dans un ordre précis (exemple : rouge → orange → bleu → vert).

## 🚀 Installation et Exécution
1. **Cloner le dépôt GitHub** :
   ```sh
   git clone https://github.com/jshelb200/IA-vison.git
   cd IA-vison
   ```
2. **Ouvrir le projet dans l’IDE Arduino** et charger le code sur l’**Arduino Mega**.
3. **Configurer la caméra Huskylens** avec les modèles d’apprentissage pré-entraînés.
4. **Exécuter le programme** et observer les réactions du robot.

## 📜 Crédits
Projet réalisé dans le cadre du **TP SYS4041 - Robotique** à l’ESIEA.

👨‍🏫 **Encadrants** : A. Mazzola, S. Bertrand  
📧 **Contact** : amazzola@et.esiea.fr  
👤 **Développé par** : Jérôme EVI

---
🚀 **Expérimentez la robotique avec IA Vision !** 🤖🔥

