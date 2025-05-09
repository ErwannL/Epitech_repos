import { View, Text, StyleSheet, Image, ScrollView, TouchableOpacity, Linking} from "react-native";
import React, { useState, useEffect } from 'react';
import Header from "./Header";
import axios from "axios";
import DraggableFlatList from 'react-native-draggable-flatlist';
import {GestureHandlerRootView} from 'react-native-gesture-handler'

const styles = StyleSheet.create({
  back: {
    backgroundColor: '#e5e5e5',
  },

  Container: {
    marginTop: 10,
    Bottom: 10,
    width: 'auto',
    paddingVertical: 15,
    alignItems: "center",
  },

  row: {
    flexDirection: 'row',
    alignSelf: "center",
  },

  empty_square: {
    width: 130,
    height: 130,
    backgroundColor: '#e5e5e5',
    marginLeft: 20,
    marginRight: 20,
    borderRadius: 20,
  },

  square: {
    width: 'auto',
    height: 120,
    backgroundColor: 'white',
    borderRadius: 20,
    margin: 10,
  },

  fakesquare: {
    width: 'auto',
    height: 120,
    backgroundColor: null,
    position: "relative",
    borderRadius: 20,
    margin: 10,
  },

  squareplus: {
    width: 'auto', 
    height: 130,
    backgroundColor: 'white',
    margin: 10,
    borderRadius: 20,
    justifyContent: 'center',
    alignItems: 'center',
  },

  squareDiscord: {
    width: 130, 
    height: 130,
    backgroundColor: 'white', 
    marginLeft: 20,
    marginRight: 20,
    borderRadius: 20,
    justifyContent: 'center',
    alignItems: 'center',
  },

  text: {
    fontWeight: "bold",
    fontSize: 20,
    padding: 20,
    position: "absolute",
    left: 0,
  },

  minustext: {
    padding: 2,
  },

  collegues: {
    width:'auto',
    height:30,
    marginTop:10,
    marginLeft: 10,
    borderRadius: 20,
  },

  CircleShape: {
    RedCircle: {
      marginRight:100,
      marginTop:5,
      width: 20,
      height: 20,
      borderRadius: 100,
      backgroundColor: 'red',
    },
    GreenCircle: {
      marginRight:100,
      marginTop:5,
      width: 20,
      height: 20,
      borderRadius: 100,
      backgroundColor: 'green',
    },
    YellowCircle: {
      marginRight:100,
      marginTop:5,
      width: 20,
      height: 20,
      borderRadius: 100,
      backgroundColor: 'yellow',
    },
  },

  boderNote: {
    width:'auto',
    height:30,
    backgroundColor:"#f39aff",
    borderTopLeftRadius: 20,
    borderTopRightRadius: 20,
    flexDirection: "row",
    alignItems: "center",
    marginBottom:5,
  },
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  widget: {
    backgroundColor: 'lightblue',
    padding: 10,
    margin: 5,
  },
  addButton: {
    flexDirection: 'row',
    justifyContent: "flex-end",
    padding: 10,
    margin: 5,
    borderRadius: 10,
  },
  removeButton: {
    backgroundColor: 'red',
    borderRadius: 100,
    position: "absolute",
    right: 0,
    padding: 5,
    margin: 5,
  },

});

const connectDiscord = async () => {
  const discordLoginPageURL = 'https://discord.com/login';
  Linking.canOpenURL(discordLoginPageURL)
  .then((supported) => {
    if (supported) {
      Linking.openURL(discordLoginPageURL);
    } else {
      console.error("Impossible d'ouvrir l'URL : " + discordLoginPageURL);
    }
  })
  .catch((err) => console.error('Erreur lors de l\'ouverture de l\'URL : ' + err));
};

const connectInsta = async () => {
  const instaLoginPageURL = 'https://instagram.com/';
  Linking.canOpenURL(instaLoginPageURL)
  .then((supported) => {
    if (supported) {
      Linking.openURL(instaLoginPageURL);
    } else {
      console.error("Impossible d'ouvrir l'URL : " + instaLoginPageURL);
    }
  })
  .catch((err) => console.error('Erreur lors de l\'ouverture de l\'URL : ' + err));
};

const connectTikTok = async () => {
  const tiktokLoginPageURL = 'https://tiktok.com/login';
  Linking.canOpenURL(tiktokLoginPageURL)
  .then((supported) => {
    if (supported) {
      Linking.openURL(tiktokLoginPageURL);
    } else {
      console.error("Impossible d'ouvrir l'URL : " + tiktokLoginPageURL);
    }
  })
  .catch((err) => console.error('Erreur lors de l\'ouverture de l\'URL : ' + err));
};

const connectTwitter = async () => {
  const twitterLoginPageURL = 'https://twitter.com/login';
  Linking.canOpenURL(twitterLoginPageURL)
  .then((supported) => {
    if (supported) {
      Linking.openURL(twitterLoginPageURL);
    } else {
      console.error("Impossible d'ouvrir l'URL : " + twitterLoginPageURL);
    }
  })
  .catch((err) => console.error('Erreur lors de l\'ouverture de l\'URL : ' + err));
};

const connectYoutube = async () => {
  const youtubeLoginPageURL = 'https://youtube.com/';
  Linking.canOpenURL(youtubeLoginPageURL)
  .then((supported) => {
    if (supported) {
      Linking.openURL(youtubeLoginPageURL);
    } else {
      console.error("Impossible d'ouvrir l'URL : " + youtubeLoginPageURL);
    }
  })
  .catch((err) => console.error('Erreur lors de l\'ouverture de l\'URL : ' + err));
};

const Widgets = () => {
    const [newsData, setnewsData] = useState([]);
    const [weatherData, setWeatherData] = useState(null);
    const [weatherImg, setWeatherImg] = useState(null);
    const API_KEY = '6a081ab760d3ada8a3a9576d405e826e';


  useEffect(() => {
    axios
      .get(
        `https://api.openweathermap.org/data/2.5/weather?q=Lyon&appid=${API_KEY}&units=metric`
      )
      .then((response) => {
        setWeatherImg(response.data.weather[0].icon);
        setWeatherData(response.data);
      })
      .catch((error) => {
        console.error('Erreur de requête :', error);
      });
  }, []);

    const [data, setData] = useState([
      { type: 'weather', data: {}, id:1 },
      { type: 'reminders', data: {}, id:2 },
      { type: 'collegues', data: {}, id:3 },
      { type: 'note', data: {}, id:4 },
      { type: 'discord', data: {}, id:5 },
      { type: 'addDel', data: {}, id:6 },
      { type: 'newsPapper', data: {}, id:6 },
      { type: 'insta', data: {}, id:7 },
      { type: 'tik-tok', data: {}, id:8 },
      { type: 'twitter', data: {}, id:9 },
      { type: 'youtube', data: {}, id:10 },
      { type: 'New', data: {}, id:11 },
      { type: 'New', data: {}, id:12 },
      { type: 'New', data: {}, id:13 },
      { type: 'New', data: {}, id:14 },
      { type: 'New', data: {}, id:15 },
    ]);

    const addNewWidget = () => {
      const newWidget = {
        id: data.length + 1,
        type: `New`,
      };
      const updatedData = [...data, newWidget];
      setData([...data, newWidget]);
    };
  

    const renderItem = ({ item, index, drag, isActive }) => {

      const removeWidget = () => {
        const updatedData = data.filter((widget) => widget.id !== item.id);
        setData(updatedData);
      };

      useEffect(() => {
        const fetchNewsData = async () => {
          try {
            const response = await axios.get(
              `https://newsapi.org/v2/top-headlines?country=us&apiKey=b1db1927499b4b98aa6b9f18d434a40d`
            );
            setnewsData(response.data.articles);
          } catch (error) {
            console.error("Erreur lors de la récupération des nouvelles :", error);
          }
        };
    
        fetchNewsData();
      }, []);

      switch (item.type) {
          case 'weather':
              return (
                  <TouchableOpacity onLongPress={drag}>
                     <View style={styles.square}>
                      {weatherData ? (
                        <View style={{padding:10}}>
                          <Text style={{marginBottom: 5, alignSelf: "center"}}>{weatherData.name}</Text>
                            <Image source={{uri: `http://openweathermap.org/img/w/${weatherImg}.png`,}} style={{ width: 60, height: 60, alignSelf: "center"}} />
                          <Text style={{ alignSelf: "center"}}>{weatherData.main.temp}°C</Text>
                        </View>
                      ) : (
                        <Text>Chargement...</Text>
                      )}
                      <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                        <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
                      </View>
                  </TouchableOpacity>
              );
          case 'reminders':
              return (
                  <TouchableOpacity onLongPress={drag}>
                      <View style={styles.square}>
                     <View style={styles.boderNote}>
                       <Image source={require('../assets/bell.png')} style={{ width: 30, height:30, marginLeft: 5 }} />
                       <Text style={{alignSelf: 'center' }}>{'Mes Rappels'}</Text>
                     </View>
                     <Text style={styles.minustext}>{'Rendez vous avec M.Bernand à 14h'}</Text>
                     <Text style={styles.minustext}>{'Présentation à 18h en distanciel'}</Text>
                     <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                     <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
                   </View>
                  </TouchableOpacity>
              );
          case 'collegues':
            return (
              <TouchableOpacity onLongPress={drag}>
                <View style={styles.square}>
                     <View style={styles.collegues}>
                       <View style={styles.CircleShape.GreenCircle} />
                       <Text style={{marginLeft: 30, marginTop: -20, fontSize: 12.5}}>Truc CHOUETTE</Text>
                     </View>
                     <View style={styles.collegues}>
                       <View style={styles.CircleShape.RedCircle} />
                       <Text style={{marginLeft: 30, marginTop: -20, fontSize: 12.5}}>Machin BIDULE</Text>
                     </View>
                     <View style={styles.collegues}>
                       <View style={styles.CircleShape.YellowCircle} />
                       <Image source={require('../assets/cofee.png')} style={{height: 15, width:15, marginRight: 100, marginTop: -20}} />
                       <Text style={{marginLeft: 30, marginTop: -15, fontSize: 12.5}}>Bobi BOBIBO</Text>
                     </View>
                     <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                     <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
                  </View>
              </TouchableOpacity>
            );
          case 'note':
            return (
            <TouchableOpacity onLongPress={drag}>
              <View style={styles.square}>
                   <View style={styles.boderNote}>
                     <Image source={require('../assets/folder.png')} style={{height: 20, width:20, marginLeft: 10}} />
                     <Text style={{marginLeft: 5}}>Mes Notes</Text>
                   </View>
                   <Text style={styles.minustext}>• Changer version</Text>
                   <Text style={styles.minustext}>• Pot de départ</Text>
                   <Text style={styles.minustext}>• Appeler franck</Text>
                   <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                   <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                    </TouchableOpacity>
                 </View>
            </TouchableOpacity>
          );
          case 'discord':
            return (
            <TouchableOpacity onLongPress={drag} onPress={connectDiscord} style={styles.squareplus}>
                <Image source={require('../assets/discord.png')} style={{width: 70, height:50, alignSelf: "center"}}/>
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
              </TouchableOpacity>
          );
          case 'New':
          return (
            <TouchableOpacity onLongPress={drag}>
              <View style={styles.square}>
              <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                     <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
              </TouchableOpacity>
              </View>
            </TouchableOpacity>
          );  
          case 'newsPapper':
          return (
          <View style={styles.square}>
                  <View style={styles.boderNote}>
                    <Image source={require('../assets/folder.png')} style={{height: 20, width:20, marginLeft: 10}} />
                    <Text style={{marginLeft: 5}}>NEWS</Text>
                </View>
                  {newsData.length > 0 ? (
                    <View style={styles.News}>
                      <Text style={{ fontWeight: "bold", fontSize: 12 }}>{newsData[0].title}</Text>
                      <Text>{newsData[0].description}</Text>
                    </View>
                ) : (<Text>Pas de nouvelles disponibles</Text>
                )}
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                     <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                </TouchableOpacity>
                </View>
          );
          case 'insta':
            return (
            <TouchableOpacity onLongPress={drag} onPress={connectInsta} style={styles.squareplus}>
                <Image source={require('../assets/insta.png')} style={{width: 70, height:70, alignSelf: "center"}}/>
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
              </TouchableOpacity>
          );
          case 'tik-tok':
            return (
            <TouchableOpacity onLongPress={drag} onPress={connectTikTok} style={styles.squareplus}>
                <Image source={require('../assets/tiktok.png')} style={{width: 70, height:50, alignSelf: "center"}}/>
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
              </TouchableOpacity>
          );
          case 'twitter':
            return (
            <TouchableOpacity onLongPress={drag} onPress={connectTwitter} style={styles.squareplus}>
                <Image source={require('../assets/twitter.png')} style={{width: 70, height:50, alignSelf: "center"}}/>
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
              </TouchableOpacity>
          );
          case 'youtube':
            return (
            <TouchableOpacity onLongPress={drag} onPress={connectYoutube} style={styles.squareplus}>
                <Image source={require('../assets/youtube.png')} style={{width: 70, height:50, alignSelf: "center"}}/>
                <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
                      </TouchableOpacity>
              </TouchableOpacity>
          );
          case 'New':
          return (
            <TouchableOpacity onLongPress={drag}>
              <View style={styles.square}>
              <TouchableOpacity onPress={removeWidget} style={styles.removeButton}>
                     <Image source={require('../assets/poubelle.png')} style={{width: 20, height:20}}></Image>
              </TouchableOpacity>
              </View>
            </TouchableOpacity>
          );  
          default:
              return null;
      }
  };

    return (
    <View>
          <Header />
        <GestureHandlerRootView>
          <TouchableOpacity onPress={addNewWidget} style={styles.addButton}>
            <Image source={require('../assets/plus.png')} style={{height: 40, width: 40}}></Image>
          </TouchableOpacity>
        <Text style={styles.text}>Mes Widgets,</Text>
          <DraggableFlatList style={styles.FlatList}
              data={data}
              renderItem={renderItem}
              keyExtractor={(item, index) => `draggable-item-${index}`}
              onDragEnd={({ data }) => setData(data)}
          />
          </GestureHandlerRootView>
    </View>
    );
};

export default Widgets;
