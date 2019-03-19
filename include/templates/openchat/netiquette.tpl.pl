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
      <p>Ponosisz odpowiedzialno�� za wszystko co wyp�ywa z twojego konta. Wymienienione poni�ej zachowania, to cz�� wykrocze� za kt�re Operator mo�e zablokowa� twoje konto:</p>
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
                      <li>zastraszanie obra�annie, stwarzanie niemi�ej atmosfery lub  poczucia dyskomfortu u innego u�ytkownika chata lub innych os�b, kt�rych dotyczy twoje zachoanie;
                      </li>
                      <li>przesylanie przez Chat informacji, danych, tekst�w, plik�w, link�w, oprogramowania lub innych materia��w, ktore Operator mo�e uzna� za bezprawne, krzywdz�ce, zastraszaj�ce, obra�aj�ce, niemoralne, rasistowskie, ksenofobiczne, wulgarne lub obsceniczne;
                      </li>
                      <li>powodowanie 'powodzi' - powodowanie scrollowania ekranu szybciej ni� inny u�ytkownik b�dzie w stanie czytac lub odpisa�; 
                      </li>
                      <li>wp�ywanie na normalny przebieg rozmowy poprzez natarczywe przeszkadzanie innym u�ytkownikom lub inne zachowanie, kt�rego nie �ycz� sobie wsp�u�ytkownicy chata;
                      </li>
                      <li>przesy�anie lub transmitowanie materia��w reklamowych lub promocyjnych;
                      </li>
                      <li>�wiadome lub nie�wiadome �amanie prawa lokalnego, stanowego (wojew�dzkiego), pa�stwowego, zachowanie podlegaj�cego karze, a nie wymienione w chat-etykiecie
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
          <a href="index.php">Powr�t'</a>
        </li>
      </ul>
      &nbsp;<br />
      <div class="menuBox">
        <dl>
          <dt class="menuBoxTitle">&nbsp;Wi�cej informacji</dt>
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