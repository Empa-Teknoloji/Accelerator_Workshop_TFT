# TouchGFX Designer 

TouchGFX Designer, STM32 mikrodenetleyiciler için grafik arayüz tasarımını kolaylaştıran bir araçtır. Kullanıcı dostu bir ortam sunarak, sürükle-bırak yöntemiyle grafik arayüzleri oluşturmanıza olanak tanır.

## Proje Oluşturma

TouchGFX Designer üzerinden yeni bir proje oluşturmak oldukça basittir. İşte adım adım nasıl yapacağınız:

- **Adım 1:** TouchGFX Designer'ı Başlatın.  
- **Adım 2:** TouchGFX Designer'ı açtıktan sonra, ekranın sol üst köşesinde bulunan "Create New" butonuna tıklayın. Bu, yeni bir proje oluşturma sihirbazını başlatacaktır.  
- **Adım 3:** Kullanacağımız STM32 mikrodenetleyicisini seçin.  
- **Adım 4:** Yeni proje için bir isim ve dosyanın kaydedileceği yeri belirleyin ve Create butonuna tıklayın.

<div align="center">
  <img width="80%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Designer_1.png">
</div>
<br />

Proje oluşturma tamamlandı. Şimdi TouchGFX'in arayüzünü tanıyalım. 

<div align="center">
  <img width="80%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Designer_2.png">
</div>
<br />

**1-File, Edit, Code, Help Menüleri:** Sol üstte bulunan bu menüler, proje dosyalarını yönetmek, düzenlemek, kod yazmak ve yardım almak için kullanılır. Örneğin, yeni bir proje oluşturmak veya mevcut bir projeyi açmak için "File" menüsünü kullanabilirsiniz.

**2-Screens:** Bu bölüm, uygulamanızın ekranlarını yönetmek için kullanılır. "Add Screen" butonu ile yeni bir ekran ekleyebilirsiniz. 

<div align="center">
  <img width="80%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Designer_3.png">
</div>
<br />  

**2-Images ve Texts:** Bu bölümler, uygulamanızda kullanacağınız görselleri ve metinleri yönetmek için kullanılır. Görselleri ve metinleri buradan ekleyebilir ve düzenleyebilirsiniz.  

**4-Config:** Bu bölüm, uygulamanızın genel yapılandırma ayarlarını içerir. Örneğin, dil ayarları veya diğer genel özellikler burada yapılır.  

**5-Files:** Bu bölüm, projenizde kullanılan dosyaları listeler. Görseller, fontlar ve diğer kaynaklar burada görüntülenebilir.

**6-Objeler Paleti:**
- **Buttons:** Butonlar, kullanıcı etkileşiminde kullanılan temel bileşenlerdir. Bir butona tıklandığında bir eylemi tetikleyebilirsiniz. 

  - Button: Temel buton türüdür. Kullanıcı etkileşimi için kullanılır. 

  - Button With Label: Üzerinde metin etiketi bulunan butondur. Kullanıcıya butonun işlevi hakkında bilgi verir.  

  - Button With Icon: Üzerinde simge (ikon) bulunan butondur. Görsel bir temsil sağlar.  

  - Toggle Button: Açma/kapama işlevi gören butondur. Durumu değiştirilebilir (açık/kapalı).  

  - Radio Button: Kullanıcıya birden fazla seçenek sunulduğunda, bu seçeneklerden yalnızca birini seçmesine olanak tanıyan bir buton türüdür. Genellikle gruplar halinde kullanılır.  

  - Repeat Button: Basılı tutulduğunda sürekli olarak tetiklenen butondur. Örneğin, artırma/azaltma işlemleri için kullanılır.  

  - Flex Button: Esnek yapıda olan, farklı boyut ve şekillerde özelleştirilebilen butondur.  

  <div align="center">
    <img width="50%" height="70%" src="../../STM32CubeIDE/Documents/Images/Buttons\ButtonsAll.png"> 
  </div>
  <br />

- **İmages:** Bu bölüm, kullanıcı arayüzüne (UI) görseller eklemek ve yönetmek için kullanılır. İşte temel bileşenler:  

  - Image: Statik bitmap görüntüler (PNG, JPEG). Bir görüntü dosyasından alınan piksel verilerini kullanır ve boyutu çalışma zamanında değiştirilemez.  
  
  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images\TouchGFX_Images\Image1.png">
  </div>
  <br />  
  
  - Scalable: Bir bitmap görüntüsünü ölçekleyerek çizebilen bir bileşendir; genişlik ve yükseklik değerleri değiştirilerek yeniden boyutlandırılabilir. 

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images\Scalable_Image.png">
  </div>
  <br />

  -  Tiled Image: Genişlettikçe tekrarlayan desenler oluşturur. Arka planlar için idealdir.

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images\Tiled_Image.png">
  </div>
  <br />

  - Animated Image: Animated Image, bir dizi görüntüyle animasyon başlatıp çalıştırır ve animasyonu tek sefer veya döngüsel olarak oynatabilir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images/Animated_Image.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Texture Mapper: Texture Mapper, ölçeklenip döndürülebilen dönüştürülmüş bir görüntü çizer. Perspektif etkisi sanal kamera ile ayarlanabilir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images/Texture_Mapper.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>


  - SVG Image: SVG Görseli, bir SVG görsel dosyasını çizebilen ve ayarlanabilir bir döndürme merkezi etrafında serbestçe ölçeklenip döndürülebilen bir bileşendir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images/Svg_Image.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - QR Code: Dinamik olarak QR kod oluşturur. URL veya metin bağlantıları eklemek için kullanılır.

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/TouchGFX_Images\QR_Code.png">
  </div>
  <br />

- **Containers:** Kullanıcı arayüzü (UI) tasarımında farklı içerikleri düzenlemek ve ekrana yerleştirmek için kullanılan araçlardır.

  - Container: TouchGFX’te birden fazla öğeyi (buton, resim, metin vb.) gruplamak ve düzenlemek için kullanılan bir bileşendir. İçerdiği bileşenleri bir arada tutarak, konumlandırma ve yönetimi kolaylaştırır.

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/Containers\Container.png">
  </div>
  <br />  

  - Scrollable Container: İçerik çok büyük olduğunda, kullanıcının ekranı kaydırarak içerikleri görmesini sağlar. Uzun içerikler için idealdir.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Scrollable_Container.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Swipe Container: Parmağınızla sağa veya sola kaydırarak içerik değiştirmenizi sağlar. Örneğin, fotoğraf galerisi gibi uygulamalarda kullanılır.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Swipe_Container.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - List Layout: İçerik öğelerini dikey veya yatay liste şeklinde düzenler. Özellikle liste halindeki veriler için kullanılır.

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/Containers\List_Layout.png">
  </div>
  <br />  

  - Modal Window: Açıldığında ekranın tamamını kaplayan ve alttaki öğelerle etkileşimi engelleyen bir pencere bileşenidir. Genellikle kullanıcıdan onay almak veya önemli bir mesaj göstermek için kullanılır. Arka planı karartılabilir ve pencere kapanana kadar diğer butonlar veya alanlar tıklanamaz hale gelir.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Modal_Window.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Scroll List: Liste içeriği, ekranı kaydırarak görmenizi sağlar. Özellikle uzun liste öğeleri için kullanılır.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Scroll_List.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Scroll Wheel: döner bir menü yapısıdır ve içindeki öğeler kaydırıldıkça güncellenir. Seçilen öğe merkeze getirilerek vurgulanır ve kullanıcı etkileşimlerine göre belirli işlemler tetiklenebilir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Scroll_Wheel.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Slide Menu: Menü, ekranın kenarından kaydırarak açılır. Bu tür menüler, ekranın daha verimli kullanılmasını sağlar ve genellikle mobil uygulamalarda tercih edilir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Containers/Slide_Menu.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

- **Shapes:** Shapes menüsünde, tasarımda kullanılan farklı şekiller bulunur. Bu şekiller, kutular, çizgiler, daireler ve daha fazlasını içerebilir, grafiksel öğeler oluşturmak için kullanılır.  

- **Progress Indicators:** Bir işlemin veya sürecin ne kadarının tamamlandığını görsel olarak gösteren araçları içerir.

  - Box Progress: Bir işlemdeki ilerlemeyi göstermek için basit bir kutu kullanarak ilerleme göstergesi sağlar.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Progress_indicators/Box_Progress.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Image Progress: Bu tür bir ilerleme göstergesi, genellikle bir arka plan görseli üzerine yerleştirilir. İlerleme görüntüsü, kullanıcının belirlediği yönde hareket eder ve ilerleme oranı arttıkça görselin bir kısmı görünür hale gelir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Progress_indicators/Image_Progress.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Text Progress: İlerleme, metin şeklinde gösterilir ve genellikle yüzdelik değerlerle ifade edilir (örneğin, %50 tamamlandı).  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Progress_indicators/Text_Progress.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Line Progress: ilerlemeyi bir çizgi ile gösterir ve bu çizgi, arka planın üzerinde istediğiniz bir yerden başlayıp başka bir yere kadar uzanabilir.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Progress_indicators/Line_Progress.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Circle Progress: İlerleme, bir daire etrafında döner. Bu tür gösterge, işlem tamamlandıkça dairenin bir kısmının dolmasını simüle eder.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Progress_indicators/Circle_Progress.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

- **Miscellaneous:** Miscellaneous menüsünde yer alan bileşenler, kullanıcı arayüzü tasarımında farklı işlevleri yerine getiren öğelerdir. Bu bileşenler şunlardır:

  - Slider: Kullanıcının bir değeri görsel olarak    ayarlayabilmesi için kullanılan kaydırma çubuğu.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Slider.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Text Area: Metin girişi yapabileceğiniz ya da metin görüntüleyebileceğiniz alan.  

  - Analog Clock: Saatin analog biçimde gösterimi.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Analog_Clock.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Digital Clock: Saatin dijital biçimde gösterimi.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Digital_Clock.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Dynamic Graph: Zaman içinde değişen ve güncellenen bir grafik.  

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Dynamic_Graph.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Static Graph: Sabit bir grafik, değişmeyen bir veri sunar.  

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Static_Graph.png">
  </div>
  <br />  

  - Gauge: Ölçüm göstergesi, genellikle bir veriyi görsel olarak sunmak için kullanılır. 

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Gauge.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>

  - Video: Video oynatma bileşeni, videoların arayüzde oynatılmasına olanak sağlar.

  <div align="center">
    <video width="40%" height="70%" controls loop>
      <source src="../../STM32CubeIDE/Documents/Images/Miscellaneous/Video.mp4" type="video/mp4">
      Tarayıcınız video formatını desteklemiyor.
    </video>
  </div>



**7-Interactions:** 
TouchGFX Designer'daki Interactions sekmesi, kullanıcı arayüzünde belirli olayları yakalamak ve bunlara tepki vermek için kullanılır. Bir etkileşim, bir Trigger (Tetikleyici) ve bir Action (Eylem) olmak üzere iki ana bileşenden oluşur:  

  <div align="center">
    <img width="40%" height="70%" src="../../STM32CubeIDE/Documents/Images/Iteractions/iteractions_image1.png">
  </div>
  <br />  

- Trigger (Tetikleyici): Etkileşimi başlatan olaydır. Örneğin, bir butona tıklanması veya bir zamanlayıcının süresinin dolması gibi.​

- Action (Eylem): Tetikleyici gerçekleştiğinde yapılacak işlemdir. Örneğin, bir ekranın değiştirilmesi veya bir fonksiyonun çağrılması gibi.

**Adım Adım Kullanım**    
  
1- TouchGFX Designer'ı Açın

- Yeni bir proje oluşturun veya mevcut bir projeyi açın.​

2- Etkileşim Eklemek İçin Bir Widget Seçin

- Örneğin, bir buton ekleyin ve onu seçin.​

3- Interactions Sekmesine Gidin

- Sağ tarafta Interactions panelini göreceksiniz.​

4- Yeni Bir Etkileşim (Interaction) Ekleme

- "+" butonuna tıklayın.​

- Trigger (Tetikleyici) Seçin:

  - Button is clicked (Butona tıklanması)

  - Screen transition begins (Ekran geçişi başladığında)

  - Video is done (Video bittiğinde)

- Action (Eylem) Seçin:

  - Change screen (Ekranı değiştir)

  - Call function (Fonksiyon çağır)

  - Play video (Videoyu oynat)

5- Gerekli Parametreleri Ayarlayın

- Hangi widget'ın etkileşime gireceğini ve hangi eylemin gerçekleşeceğini belirleyin.​

6-Kod Tarafında Geliştirme

- TouchGFX Designer, otomatik olarak kod üretir, ancak bazı gelişmiş işlemler için ScreenView.hpp/.cpp dosyalarında manuel kod yazabilirsiniz.


**8-Properties:** Seçili olan öğenin özelliklerini buradan düzenleyebilirsiniz. Örneğin, bir butonun rengi veya boyutu gibi özellikler burada ayarlanır.

**9-Generate Code:** Tasarımınızı tamamladıktan sonra, oluşturduğunuz kullanıcı arayüzünü otomatik olarak C++ koduna dönüştürür. Bu, tasarımın mikrodenetleyici üzerinde çalışması için gereken kodu üretir.  

**10-Run Simulator:** Tasarımınızı bilgisayarınızda simüle etmenizi sağlar. Bu, tasarımınızın nasıl göründüğünü ve çalıştığını test etmek için kullanılır.

**11-Program and Run Target:** Tasarımı doğrudan hedef cihazınıza (mikrodenetleyici veya ekran) yükler ve çalıştırır. Bu seçenek, geliştirdiğiniz arayüzün gerçek donanımda nasıl çalıştığını test etmenizi sağlar.

 