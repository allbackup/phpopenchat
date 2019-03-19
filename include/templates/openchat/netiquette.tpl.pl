<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title>Title</title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/

    /*/]]>*/
    </script>
  </head>
  <body>
    <div class="satContent">
      <h1>Chat - etykieta</h1>
      <p>Ponosisz odpowiedzialno¶æ za wszystko co wyp³ywa z twojego konta. Wymienienione poni¿ej zachowania, to czê¶æ wykroczeñ za które Operator mo¿e zablokowaæ twoje konto:</p>
      <div class="satContentBox">
        <dl>
          <dt class="contentBoxTitle">
            &nbsp;Rules
          </dt>
          <dd>
            <table>
              <tbody>
                <tr>
                  <td>
                    <ul>
                      <li>zastraszanie obra¿annie, stwarzanie niemi³ej atmosfery lub  poczucia dyskomfortu u innego u¿ytkownika chata lub innych osób, których dotyczy twoje zachoanie;
                      </li>
                      <li>przesylanie przez Chat informacji, danych, tekstów, plików, linków, oprogramowania lub innych materia³ów, ktore Operator mo¿e uznaæ za bezprawne, krzywdz±ce, zastraszaj±ce, obra¿aj±ce, niemoralne, rasistowskie, ksenofobiczne, wulgarne lub obsceniczne;
                      </li>
                      <li>powodowanie 'powodzi' - powodowanie scrollowania ekranu szybciej ni¿ inny u¿ytkownik bêdzie w stanie czytac lub odpisaæ; 
                      </li>
                      <li>wp³ywanie na normalny przebieg rozmowy poprzez natarczywe przeszkadzanie innym u¿ytkownikom lub inne zachowanie, którego nie ¿ycz± sobie wspó³u¿ytkownicy chata;
                      </li>
                      <li>przesy³anie lub transmitowanie materia³ów reklamowych lub promocyjnych;
                      </li>
                      <li>¶wiadome lub nie¶wiadome ³amanie prawa lokalnego, stanowego (wojewódzkiego), pañstwowego, zachowanie podlegaj±cego karze, a nie wymienione w chat-etykiecie
                      </li>
                    </ul>
                  </td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
    </div>
    <div class="menu">
    <div class="flagBox"><?=$TEMPLATE_OUT['lang_switch']?></div>
      <ul>
        <li>
          <a href="index.php">Powrót'</a>
        </li>
      </ul>
      &nbsp;<br />
      <div class="menuBox">
        <dl>
          <dt class="menuBoxTitle">&nbsp;Wiêcej informacji</dt>
          <dd>
            <p>
              <a href="http://kni.ae.krakow.pl/html/netykieta/net_00.html">Netykieta</a>
            </p>
          </dd>
        </dl>
      </div>
    </div>
  </body>
</html>